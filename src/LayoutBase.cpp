#include "LayoutBase.hpp"

LayoutBase::LayoutBase() {

}
LayoutBase::LayoutBase ( std::string params ) {

}
LayoutBase::~LayoutBase() {

}
bool LayoutBase::CreateScreen ( Renderer* r, GameList* gl ) {

}


LayoutBase& LayoutBase::operator=(const LayoutBase& other)
{
  gfxRender_ = other.gfxRender_;
  gameList_ = other.gameList_;
  
}


