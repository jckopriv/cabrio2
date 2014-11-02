//
// Platform class - contains parameters of a single platform.
//
#ifndef CABRIO_PLATFORM_HPP_
#define CABRIO_PLATFORM_HPP_

#include "CabrioDataTypes.hpp"
#include "QuadMap.hpp"

class Platform {
  public:
    Platform();
  private:
    QuadMap quads_;
};

#endif
