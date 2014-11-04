//
// Game class - contains parameters of a single game.
//
#include "Game.hpp"
#include <map>

Game::Game() {
}

Game::~Game(){
  
}

Game::Game(std::string n) {
  str_name_ = n;
}

std::string Game::name() {
  return str_name_;
}

void Game::getName(std::string n) {
  str_name_ = n;
}

Quad* Game::getImageByTpe ( ImgType it ) {
  return quads_.getImage(it);
}

Platform* Game::platform() {
  return plat_;
}


bool Game::operator== ( const Game& g ) {
  if((str_name_ == g.str_name_) &&
    (plat_ == g.plat_)){
      // if name and platform are the same, we'll go with it.
   return true; 
  }
  return false;
}
