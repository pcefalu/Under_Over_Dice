//
//  HomeScene.h
//  Under-n-Over
//
//  Created by Paul Cefalu on 1/30/14.
//
//

#ifndef __Under_n_Over__HomeScene__
#define __Under_n_Over__HomeScene__

#include "cocos2d.h"


//****************************************************************************
class HomeScene : public cocos2d::LayerColor
{ // Class Data Members
  //--------------------------------------------------
  
public:
  // there's no 'id' in cpp, so we recommend returning the class instance pointer
  static cocos2d::Scene* createScene();
  
  // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
  virtual bool init();
  
  // a selector callback
  void menuExitCallback(Object* pSender);
  void menuPlayCallback(Object* pSender);
  
  void PlayButtonClick();
  
  // implement the "static create()" method manually
  CREATE_FUNC(HomeScene);
  
  //--------------------------------------------------
};// End of HomeScene Class


#endif /* defined(__Under_n_Over__HomeScene__) */
