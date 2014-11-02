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

class Renderer : Singleton<Renderer> {
  friend class Singleton<Renderer>;
  public:
    Renderer();
    ~Renderer();

    virtual int init() = 0;
    virtual int draw_all() = 0;
    int set_platform(Platform *p); //This will probably change. Intended to be Skin (background)
    int set_gamelist(GameList *gl);

  protected:
    int get_quads();
    
    std::vector<Quad> quads_;
    GameList *currGameList_;
    Platform *currPlatform_;
    bool listChanged; //trigger to be "true" on 'set' functions
  
};

#endif
