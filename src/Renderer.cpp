//
// Abstract class for all renderers.
//
#include "Renderer.hpp"

Renderer::Renderer() {

}

Renderer::~Renderer() {

}

int Renderer::set_platform(Platform* p)
{
  listChanged = true;
  quads_.clear();
  currPlatform_ = p;
  return get_quads();  
}

int Renderer::set_gamelist(GameList* gl)
{
  listChanged = true;
  quads_.clear();
  currGameList_ = gl;
  return get_quads();
}

int Renderer::get_quads()
{
  // populate based on 'platform' first
  
  // then Gamelist, with care to "current"
}

