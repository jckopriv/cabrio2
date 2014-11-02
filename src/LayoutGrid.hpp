#ifndef CABRIO_LAYOUTGRID_H
#define CABRIO_LAYOUTGRID_H


#include "LayoutBase.hpp"

class GameList;
class Renderer;

class LayoutGrid : public LayoutBase {
public:
    LayoutGrid();
    ~LayoutGrid();
    
    LayoutGrid(std::string params);
    
    bool CreateScreen(Renderer* r, GameList* gl);
    
};

#endif // LAYOUTGRID_H
