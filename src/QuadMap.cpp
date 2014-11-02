#include "QuadMap.hpp"

QuadMap::QuadMap()
{

}

QuadMap::~QuadMap()
{

}

// Returns a pointer to a Quad based on a desired Image Type
// If the map is empty, return null.
Quad* QuadMap::getImage(ImgType t){
  if(imagery_.count(t) > 0){
    return imagery_.find(t)->second;
  }
  return nullptr;
}

// Returns a pointer to a Quad based on a desired Image Type
// If the map is empty, return null.
bool QuadMap::remImage(ImgType t){
  return imagery_.erase(t) > 0;
}

// Inserts a new image into the map of <image types, quads>. 
// If an image of a type exists, return false.
bool QuadMap::addImage(std::string n, ImgType t)
{
  /*  */
  Quad *q = new Quad();
  q->texture(n);
  return(imagery_.emplace(t,q).second);
}