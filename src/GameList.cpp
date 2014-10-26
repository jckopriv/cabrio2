//
// GameList - singleton containing all games we know about.
//
#include "GameList.hpp"

GameList::GameList()
{

}

GameList::~GameList()
{

}


void GameList::add(Game& g) {
  games_.push_back(g);
}

void GameList::reset() {
  currIter = games_.begin();
}

Game& GameList::first() {
  this->reset();
  return this->next();
}

Game& GameList::next() {
  currIter++;

  if(currIter == games_.end()){
    currIter = games_.begin();
  }
  return *currIter;
}

Game& GameList::previous() {

  if(currIter == games_.begin()){
   currIter = games_.end();
  }
  currIter--;

  return *currIter;
}
