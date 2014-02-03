//
//  MainScene.h
//  Under-n-Over
//
//  Created by Paul Cefalu on 1/30/14.
//
//

#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "SimpleAudioEngine.h"
#include "Box2D/Box2D.h"
#include "cocos2d.h"
#include "CImageSprite.h"
#include "CFloor.h"
#include "CDice.h"


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
  
  
  eBidTypes       m_eBidType         = NoBid;
  eStatusTypes    m_eStatusType      = Inactive;
  
  const int       m_BidTagID         = 1;
  const int       m_StatusTagID      = 2;
  const int       m_MaxLimitDice     = 7;
  
  int             m_NumberOfDice     = 2;
  int             m_DiceHaveFallen   = 0;
  
  bool            m_bDisableRolls    = false;
  
  b2Vec2         *m_poGravity        = nullptr;
  b2World        *m_poWorld          = nullptr;
  b2Body         *m_poBody           = nullptr;
  
  CDice          *m_poDice_1         = nullptr;
  CDice          *m_poDice_2         = nullptr;

  CImageSprite   *m_poImage_1        = nullptr;
  CImageSprite   *m_poImage_2        = nullptr;

  CFloor         *m_poFloor          = nullptr;
  CFloor         *m_poBoundry        = nullptr;
  
  
public:
  MainScene();
  ~MainScene();
  

  // there's no 'id' in cpp, so we recommend returning the class instance pointer
  static cocos2d::Scene* createScene();

  // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
  virtual bool init();  
  
  // a selector callback
  void menuExitCallback(Object *pSender);
  void menuOddCallback(Object *pSender);
  void menuSevenCallback(Object *pSender);
  void menuEvenCallback(Object *pSender);
  void menuRollCallback(Object *pSender);

  void PlayButtonClick();
  void PlayWinnerSound();
  void PlaySorrySound();
  void PlayRollingSound();
  void StopRollingSound();
  
  void Tick(float dt);
  void UpdateStatusDisplay(eStatusTypes eType);
  void ProcessStatusInformation();
  
  bool TouchBegan(Touch *poTouch, Event *poEvent);
  
  std::string RtnBidTextString(eBidTypes eType);
  std::string RtnStatusTextString(eStatusTypes eType);
  
  // implement the "static create()" method manually
  CREATE_FUNC(MainScene);
  
  //--------------------------------------------------
};// End of MainScene Class


#endif // __MAIN_SCENE_H__
