//
// OpenGL Renderer implementation.
//
#include "RendererOpenGL.hpp"
#include "Logger.hpp"

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
  window = glfwCreateWindow( 1024, 768, "Tutorial 01", NULL, NULL);
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

  return 0;
}
