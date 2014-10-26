//
// OpenGL Renderer implementation.
//
#ifndef CABRIO_RENDEREROPENGL_HPP_
#define CABRIO_RENDEREROPENGL_HPP_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Renderer.hpp"

class RendererOpenGL : public Renderer {
  public:
    RendererOpenGL();
    ~RendererOpenGL();
    int init();
  private:
    GLFWwindow* window;
};

#endif
