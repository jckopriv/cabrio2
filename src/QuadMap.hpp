#ifndef QUADMAP_H
#define QUADMAP_H


#include <map>

#include "CabrioDataTypes.hpp"
#include "Quad.hpp"

class QuadMap
{
public:
    QuadMap();
    ~QuadMap();
   
    Quad* getImage(ImgType t);
    bool remImage(ImgType t);
    bool addImage(std::string n, ImgType t);
   
protected:


private:   
  std::map<ImgType, Quad*> imagery_;
};

#endif // QUADMAP_H
