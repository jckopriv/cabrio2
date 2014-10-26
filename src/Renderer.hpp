//
// Abstract class for all renderers.
//
#ifndef CABRIO_RENDERER_HPP_
#define CABRIO_RENDERER_HPP_

#include <vector>

#include "Quad.hpp"

class Renderer {
  public:
    Renderer();
    ~Renderer();

    virtual int init() = 0;
    virtual int draw_all() = 0;

    std::vector<Quad> quads;

  private:
};

#endif
