//
// Abstract class for all renderers.
//
#ifndef CABRIO_RENDERER_HPP_
#define CABRIO_RENDERER_HPP_

#include <vector>

#include "Quad.hpp"
#include "GameList.hpp"
#include "Platform.hpp"
#include "Singleton.hpp"
#include "CabrioDataTypes.hpp"

class LayoutBase;
class Renderer : Singleton<Renderer> {
  friend class Singleton<Renderer>;
  public:
    Renderer();
    ~Renderer();

    virtual int init() = 0;
    virtual int draw_all() = 0;
    
    // Quad handling should reside solely in the layout.
    // the renderer only takes in a quad list and displays it.
    int set_quads(vector<Quad> q);


  protected:
    
    std::vector<Quad> quads_;
    GameList *currGameList_;
    Platform *currPlatform_;
    bool listChanged; //trigger to be "true" on 'set' functions
  
};

#endif
