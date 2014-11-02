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

Game& GameList::current(){
  return *currIter;
}



std::vector<Game>* GameList::getRange(int count){
 std::vector<Game>* ret;

 // TODO: Handle wrapping around the boundaries of the games vector.

  //iterator can handle ++/-- as well as +n and -n.
   // this should return 'count' games both before and after Current
 
 return ret; 
}