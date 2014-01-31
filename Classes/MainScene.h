//
//  MainScene.h
//  Under-n-Over
//
//  Created by Paul Cefalu on 1/30/14.
//
//

#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"

using namespace cocos2d;


//****************************************************************************
class MainScene : public cocos2d::LayerColor
{ // Class Data Members
  //--------------------------------------------------
  
private:
  enum eBidTypes
  { // Bid Types
    //--------------
    NoBid, OddBid, SevenBid, EvenBid
  };
  
  enum eStatusTypes
  { // Status Types
    //--------------
    Inactive, Winner, Loser
  };
  
  
  eBidTypes           m_eBidType     = NoBid;
  eStatusTypes        m_eStatusType  = Inactive;
  
  cocos2d::LabelTTF  *m_BidLabel     = nullptr;
  cocos2d::LabelTTF  *m_StatusLabel  = nullptr;
  
public:
  // there's no 'id' in cpp, so we recommend returning the class instance pointer
  static cocos2d::Scene* createScene();

  // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
  virtual bool init();  
  
  // a selector callback
  void menuExitCallback(Object* pSender);
  void menuOddCallback(Object* pSender);
  void menuSevenCallback(Object* pSender);
  void menuEvenCallback(Object* pSender);
  void menuRollCallback(Object* pSender);

  void PlayButtonClick();
  void Tick(float dt);
  void CreateDice(Point oPoint);
  
  bool TouchBegan(Touch *poTouch, Event *poEvent);
  
  std::string RtnBidTextString(eBidTypes eType);
  std::string RtnStatusTextString(eStatusTypes eType);
  
  // implement the "static create()" method manually
  CREATE_FUNC(MainScene);
  
  //--------------------------------------------------
};// End of MainScene Class


#endif // __MAIN_SCENE_H__
