#include "LayoutBase.hpp"

LayoutBase& LayoutBase::operator=(const LayoutBase& other)
{
  gfxRender_ = other.gfxRender_;
  gameList_ = other.gameList_;
  
}

bool LayoutBase::operator==(const LayoutBase& other)
{

}
