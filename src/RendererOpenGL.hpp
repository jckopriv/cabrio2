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
    int draw_all();
  private:
    GLFWwindow* window;
    GLuint program_id;
    GLuint matrix_id;
};

#endif
