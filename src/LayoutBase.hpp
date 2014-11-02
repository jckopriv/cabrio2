#ifndef CABRIO_LAYOUTBASE_H
#define CABRIO_LAYOUTBASE_H

#include "Renderer.hpp"
#include "GameList.hpp"
#include "CabrioDataTypes.hpp"

class LayoutBase
{
public:
    virtual LayoutBase();
    virtual LayoutBase(std::string params); // this may end up being a struct or xmlnode
    virtual ~LayoutBase();
    LayoutBase& operator=(const LayoutBase& other);
    bool operator==(const LayoutBase& other);

    //TODO This will set up positions for quads based on Layout files
    // then populate the Render quads appropriately.
    
private:
    Renderer* gfxRender_;
    GameList* gameList_;
    Uint16 maxOnScreen; /* max count to show on screen */
};

#endif // LAYOUTBASE_H
