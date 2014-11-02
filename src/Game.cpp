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

void Game::name(std::string n) {
  str_name_ = n;
}

