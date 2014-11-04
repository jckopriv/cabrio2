#include "LayoutGrid.hpp"
#include "Renderer.hpp"
#include "GameList.hpp"

LayoutGrid::LayoutGrid() {

}

LayoutGrid::~LayoutGrid() {

}

LayoutGrid::LayoutGrid ( std::string params ) {

}

bool LayoutGrid::CreateScreen ( Renderer* r, GameList* gl ) {

  if(gl->current() == gameList_->current()){
    // here is where the majic of user input combining with display to user happens.
    // still thinking about best way to go about it.
    
    // lay out background media
      // populate based on 'platform' first
  for(auto iter : currPlatform_->get_quads()){
    //TODO: position based on stored coords for image type
   quads_.push_back(*iter); 
  }
  
  
  // then Gamelist, with care to "current"
  for(auto iter : currGameList_->getRange(maxOnScreen)){
    if(*iter != currGameList_->current()){
      // TODO:Generate a default if null

      quads_.push_back(iter->getImageByType(ImgType::LOGO)); 
    } else {
    // special handling for current selection.
      // dislay art the user has selected:
      // for all art esuer selected
      //   switch on current iteration
      //     case ImgType:
      //      quads_.pushback(curr->getImageByType(ImgType::)
      //      break
      //  end switch
      // end for    
    }
  }
//  r->set_quads()
  }
}
