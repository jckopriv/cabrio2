//
// Game class - contains parameters of a single game.
//
#ifndef CABRIO_GAME_HPP_
#define CABRIO_GAME_HPP_

#include <string>

#include "CabrioDataTypes.hpp"
#include "Platform.hpp"
#include "QuadMap.hpp"

class Quad;

class Game {
  public:
    Game();
    Game(std::string name);
    ~Game();

    Platform* platform();
    std::string name();
    void getName(std::string n);
    Quad* getImageByTpe(ImgType it);

    bool operator==(const Game& g);
    
  private:
    std::string str_name_;
    Platform *plat_;
    QuadMap quads_;
};

#endif
