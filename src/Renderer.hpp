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

    void add_quad(Quad& q);

    virtual int init() = 0;
  private:
    std::vector<Quad> quads;
};

#endif
