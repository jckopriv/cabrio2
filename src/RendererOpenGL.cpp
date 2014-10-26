//
// OpenGL Renderer implementation.
//
#include "RendererOpenGL.hpp"
#include "Logger.hpp"


static const GLfloat g_vertex_quad[] = {
  -1.0f, -1.0f, 0.0f,
   1.0f, -1.0f, 0.0f,
   1.0f,  1.0f, 0.0f,
  -1.0f,  1.0f, 0.0f,
};


RendererOpenGL::RendererOpenGL() {

}

RendererOpenGL::~RendererOpenGL() {

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

  glClearColor(0.4f, 0.0f, 0.0f, 0.0f);

  return 0;
}

int RendererOpenGL::draw_all() {
  std::vector<Quad>::iterator i;

  i = this->quads.begin();

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  while (i != this->quads.end()) {
    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

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

    glDrawArrays(GL_QUADS, 0, 4);
    glDisableVertexAttribArray(0);

    i++;
  }

  glfwSwapBuffers(window);

  return 0;
}

