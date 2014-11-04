#ifndef CABRIO_LAYOUTBASE_H
#define CABRIO_LAYOUTBASE_H

#include <map>

#include "Renderer.hpp"
#include "GameList.hpp"
#include "CabrioDataTypes.hpp"

struct ImgPos {
  float_t x, y, z, a; // x pos, y pos, z pos, alpha
  float_t h, w; // height and width
  
};

class LayoutBase
{
public:
    LayoutBase();
    LayoutBase(std::string params); // this may end up being a struct or xmlnode
    virtual ~LayoutBase();
    LayoutBase& operator=(const LayoutBase& other);

    //TODO This will set up positions for quads based on Layout files
    // then populate the Render quads appropriately.
    
    virtual bool CreateScreen(Renderer *r, GameList *gl);
    
protected:
    Renderer* gfxRender_ = nullptr;
    GameList* gameList_ = nullptr;
    Uint16 maxOnScreen = 7; /* max count to show on screen */
    
    std::map<ImgType, ImgPos> imgCoords_;
};

#endif // LAYOUTBASE_H
