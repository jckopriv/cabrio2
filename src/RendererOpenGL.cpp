//
// OpenGL Renderer implementation.
//
#include "RendererOpenGL.hpp"
#include "Logger.hpp"

#include <ios>
#include <fstream>
#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

using namespace std;

static const GLfloat g_vertex_quad[] = {
  -1.0f,  1.0f, 0.0f,
   1.0f,  1.0f, 0.0f,
   1.0f, -1.0f, 0.0f,
  -1.0f, -1.0f, 0.0f,
};


RendererOpenGL::RendererOpenGL() {

}

RendererOpenGL::~RendererOpenGL() {

}

GLuint LoadShaders(){
  // Create the shaders
  GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
  GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

  std::string VertexShaderCode;
  VertexShaderCode += "#version 330 core\n";
  VertexShaderCode += "layout(location = 0) in vec3 vertexPosition_modelspace;\n";
  VertexShaderCode += "uniform mat4 MVP;\n";
  VertexShaderCode += "void main(){\n";
  VertexShaderCode += "  vec4 v = vec4(vertexPosition_modelspace,1);\n";
  VertexShaderCode += "  gl_Position = MVP * v;\n";
  VertexShaderCode += "}\n";

  std::string FragmentShaderCode;
  FragmentShaderCode += "#version 330 core\n";
  FragmentShaderCode += "out vec3 color;\n";
  FragmentShaderCode += "void main(){\n";
  FragmentShaderCode += "  color = vec3(1,0,0);\n";
  FragmentShaderCode += "}\n";

  GLint Result = GL_FALSE;
  int InfoLogLength;

  // Compile Vertex Shader
  char const * VertexSourcePointer = VertexShaderCode.c_str();
  glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
  glCompileShader(VertexShaderID);

  // Check Vertex Shader
  glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
  glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
  if ( InfoLogLength > 0 ){
    std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
    glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
    printf("%s\n", &VertexShaderErrorMessage[0]);
  }

  // Compile Fragment Shader
  char const * FragmentSourcePointer = FragmentShaderCode.c_str();
  glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
  glCompileShader(FragmentShaderID);

  // Check Fragment Shader
  glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
  glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
  if ( InfoLogLength > 0 ){
    std::vector<char> FragmentShaderErrorMessage(InfoLogLength+1);
    glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
    printf("%s\n", &FragmentShaderErrorMessage[0]);
  }

  // Link the program
  GLuint ProgramID = glCreateProgram();
  glAttachShader(ProgramID, VertexShaderID);
  glAttachShader(ProgramID, FragmentShaderID);
  glLinkProgram(ProgramID);

  // Check the program
  glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
  glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
  if ( InfoLogLength > 0 ){
    std::vector<char> ProgramErrorMessage(InfoLogLength+1);
    glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
    printf("%s\n", &ProgramErrorMessage[0]);
  }

  glDeleteShader(VertexShaderID);
  glDeleteShader(FragmentShaderID);

  return ProgramID;
}

int RendererOpenGL::init() {
  Logger& logger = Logger::get_instance();

  // Initialise GLFW
  if(!glfwInit()) {
    logger.log(LOG_ERROR, "Failed to initialise GLFW");
    return -1;
  }

  logger.log(LOG_INFO, "Initialised GLFW");

  glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL

  // Open a window and create its OpenGL context
  window = glfwCreateWindow( 1024, 768, "Cabrio", NULL, NULL);
  if( window == NULL ){
    logger.log(LOG_ERROR, "Failed to open GLFW window (possible OpenGL version incompatibility)" );
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);

  glewExperimental=true;
  if (glewInit() != GLEW_OK) {
    logger.log(LOG_ERROR, "Failed to initialise GLEW");
    return -1;
  }

  glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

  GLuint VertexArrayID;
  glGenVertexArrays(1, &VertexArrayID);
  glBindVertexArray(VertexArrayID);

  program_id = LoadShaders();

  // Get a handle for our "MVP" uniform.
  // Only at initialisation time.
  matrix_id = glGetUniformLocation(program_id, "MVP");

  return 0;
}

int RendererOpenGL::draw_all() {
  std::vector<Quad>::iterator i;

  i = this->quads.begin();

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glUseProgram(program_id);

  while (i != this->quads.end()) {

    // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
    glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    // Camera matrix
    glm::mat4 View       = glm::lookAt(
      glm::vec3(4,3,3), // Camera is at (4,3,3), in World Space
      glm::vec3(0,0,0), // and looks at the origin
      glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
    );

    // Model matrix : an identity matrix (model will be at the origin)
    glm::mat4 Model      = glm::mat4(1.0f);  // Changes for each model !
    // Our ModelViewProjection : multiplication of our 3 matrices
    glm::mat4 MVP        = Projection * View * Model; // Remember, matrix multiplication is the other way around

    glUniformMatrix4fv(matrix_id, 1, GL_FALSE, &MVP[0][0]);


    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_quad), g_vertex_quad, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
       0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
       3,                  // size
       GL_FLOAT,           // type
       GL_FALSE,           // normalized?
       0,                  // stride
       (void*)0            // array buffer offset
    );

    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(0);

    i++;
  }

  glfwSwapBuffers(window);

  return 0;
}

