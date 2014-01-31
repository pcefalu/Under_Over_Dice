//
//  MainScene.cpp
//  Under-n-Over
//
//  Created by Paul Cefalu on 1/30/14.
//
//
#include <SimpleAudioEngine.h>
#include <Box2D/Box2D.h>
#include <iostream>

#include "MscConstants.h"
#include "MainScene.h"


b2World  *poWorld;
b2Vec2    oGravity;



//============================================================================
Scene* MainScene::createScene()
{ // Declare Variables
  //--------------------------------------------------
  
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
  
  //--------------------------------------------------
} // End of createScene Method


//============================================================================
std::string MainScene::RtnBidTextString(eBidTypes eType)
{ // Declare Variables
  //--------------------------------------------------
  
  std::string strRet = "";
  
  switch(eType)
  {
    case OddBid:
      strRet = "ODD";
      break;
      
    case SevenBid:
      strRet = "SEVEN";
      break;
      
    case EvenBid:
      strRet = "EVEN";
      break;
      
    default:
      strRet = "Make a Selection...";
      break;
  }
  
  return strRet;
  
  //--------------------------------------------------
} // End of RtnBidTextString Method


//============================================================================
std::string MainScene::RtnStatusTextString(eStatusTypes eType)
{ // Declare Variables
  //--------------------------------------------------
  
  std::string strRet = "";
  
  switch(eType)
  {
    case Winner:
      strRet = "WINNER";
      break;
      
    case Loser:
      strRet = "SORRY...";
      break;
      
    default:
      strRet = "         ";
      break;
  }
  
  return strRet;
  
  //--------------------------------------------------
} // End of RtnStatusTextString Method


//============================================================================
bool MainScene::init()
{ // on "init" you need to initialize your instance
  //--------------------------------------------------
  
  float sngHorzSkew = 0;
  float sngVertSkew = 0;

  if( !LayerColor::initWithColor(Color4B(0, 90, 65, 255)) ) //RGBA
  {
    return false;
  }
  
  Size visibleSize = Director::getInstance()->getVisibleSize();
  Point origin = Director::getInstance()->getVisibleOrigin();
  
  
  // Create Status Label
  //--------------------------------------------------
  m_StatusLabel = LabelTTF::create(RtnStatusTextString(Inactive), "Arial", 60);
  m_StatusLabel->setPosition(Point(origin.x + visibleSize.width/2, origin.y + visibleSize.height - m_StatusLabel->getContentSize().height));
  this->addChild(m_StatusLabel, 1);
  
  
  // Create Bid Label
  //--------------------------------------------------
  m_BidLabel     = LabelTTF::create(RtnBidTextString(NoBid), "Arial", 36);
  sngHorzSkew    = m_BidLabel->getContentSize().width/2 + 10 + (visibleSize.width - m_BidLabel->getContentSize().width)/2;
  sngVertSkew    = m_BidLabel->getContentSize().height/2;

  m_BidLabel->setPosition(Point(origin.x + sngHorzSkew, origin.y + sngVertSkew + 90));
  this->addChild(m_BidLabel, 1);
  
  
  // Create Exit Button
  //--------------------------------------------------
  auto ExitItem = MenuItemImage::create("Exit Button.png", "Exit Button.png", CC_CALLBACK_1(MainScene::menuExitCallback, this));
  ExitItem->setScale(.75, .5);
  
  sngHorzSkew = ExitItem->getContentSize().width/2;
  sngVertSkew = ExitItem->getContentSize().height/2 + visibleSize.height - ExitItem->getContentSize().height;
	ExitItem->setPosition(Point(origin.x + sngHorzSkew, origin.y + sngVertSkew));
  
  auto ExitButton = Menu::create(ExitItem, NULL);
  ExitButton->setPosition(Point::ZERO);
  this->addChild(ExitButton, 1);
  
  
  // Create Seven Button
  //--------------------------------------------------
  auto SevenItem = MenuItemImage::create("Seven Button.png", "Seven Button.png", CC_CALLBACK_1(MainScene::menuSevenCallback, this));
  SevenItem->setScale(.75, .5);
  
  sngHorzSkew = SevenItem->getContentSize().width/2 + 10 + (visibleSize.width - SevenItem->getContentSize().width)/2;
  sngVertSkew = SevenItem->getContentSize().height/2;
	SevenItem->setPosition(Point(origin.x + sngHorzSkew, origin.y + sngVertSkew));
  
  auto SevenButton = Menu::create(SevenItem, NULL);
  SevenButton->setPosition(Point::ZERO);
  this->addChild(SevenButton, 1);
  
  
  // Create Odd Button
  //--------------------------------------------------
  auto OddItem = MenuItemImage::create("Odd Button.png", "Odd Button.png", CC_CALLBACK_1(MainScene::menuOddCallback, this));
  OddItem->setScale(.75, .5);
  
  sngHorzSkew = OddItem->getContentSize().width/2 + 50 - SevenItem->getContentSize().width + (visibleSize.width - OddItem->getContentSize().width)/2;
  sngVertSkew = OddItem->getContentSize().height/2;
	OddItem->setPosition(Point(origin.x + sngHorzSkew, origin.y + sngVertSkew));
  
  auto OddButton = Menu::create(OddItem, NULL);
  OddButton->setPosition(Point::ZERO);
  this->addChild(OddButton, 1);
  
  
  // Create Even Button
  //--------------------------------------------------
  auto EvenItem = MenuItemImage::create("Even Button.png", "Even Button.png", CC_CALLBACK_1(MainScene::menuEvenCallback, this));
  EvenItem->setScale(.75, .5);
  
  sngHorzSkew = EvenItem->getContentSize().width/2 + SevenItem->getContentSize().width + (visibleSize.width - EvenItem->getContentSize().width)/2;
  sngVertSkew = EvenItem->getContentSize().height/2;
	EvenItem->setPosition(Point(origin.x + sngHorzSkew - 30, origin.y + sngVertSkew));
  
  auto EvenButton = Menu::create(EvenItem, NULL);
  EvenButton->setPosition(Point::ZERO);
  this->addChild(EvenButton, 1);
  
  
  // Create Roll Button
  //--------------------------------------------------
  auto RollItem = MenuItemImage::create("Roll Button.png", "Roll Button.png", CC_CALLBACK_1(MainScene::menuRollCallback, this));
  RollItem->setScale(.75, .5);
  
  sngHorzSkew = visibleSize.width - 235 + RollItem->getContentSize().width/2;
  sngVertSkew = RollItem->getContentSize().height/2 + visibleSize.height - RollItem->getContentSize().height;
	RollItem->setPosition(Point(origin.x + sngHorzSkew, origin.y + sngVertSkew));
  
  auto RollButton = Menu::create(RollItem, NULL);
  RollButton->setPosition(Point::ZERO);
  this->addChild(RollButton, 1);
  
  
  // Create Dice Sprite
  //--------------------------------------------------
//  auto sprite = Sprite::create("MainScene.png");
//
//  // position the sprite on the center of the screen
//  sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
//
//  // add the sprite as a child to this layer
//  this->addChild(sprite, 0);
  
  CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Music Loop.mp3");
  CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Music Loop.mp3", true);
  CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(.05);
  
  
  // Create and Configure Physics
  //--------------------------------------------------
  oGravity.Set(0.0f, -WORLD_TO_SCREEN(9.8));
  bool bDoSleep = true;
  
  poWorld = new b2World(oGravity);
  poWorld->SetAllowSleeping(bDoSleep);
  
  auto poTouchListener           = EventListenerTouchOneByOne::create();
  poTouchListener->onTouchBegan  = CC_CALLBACK_2(MainScene::TouchBegan, this);
  getEventDispatcher()->addEventListenerWithFixedPriority(poTouchListener, 100);
  
  schedule(schedule_selector(MainScene::Tick));
  
  return true;
  
  //--------------------------------------------------
} // End of init Method


//============================================================================
void MainScene::CreateDice(Point oPoint)
{ // Declare Variables
  //--------------------------------------------------
  
  auto DiceSprite = Sprite::create("Dice Button.png");
  DiceSprite->setPosition(oPoint);
  this->addChild(DiceSprite, 0);
  
  b2BodyDef oDiceBodyDef;
  oDiceBodyDef.type      = b2_dynamicBody;
  oDiceBodyDef.position  = b2Vec2(DiceSprite->getPositionX(), DiceSprite->getPositionY());
  oDiceBodyDef.userData  = DiceSprite;
  
  auto DiceBody          = poWorld->CreateBody(&oDiceBodyDef);
  
  b2CircleShape oCircle;
  oCircle.m_radius       = WORLD_TO_SCREEN(0.6);
  
  b2FixtureDef oDiceFixtureDef;
  oDiceFixtureDef.shape        = &oCircle;
  oDiceFixtureDef.density      = 1.0f;
  oDiceFixtureDef.friction     = 0.6f;
  oDiceFixtureDef.restitution  = 0.8f;
  
  DiceBody->CreateFixture(&oDiceFixtureDef);
  
  //--------------------------------------------------
} // End of CreateDice Method


//============================================================================
void MainScene::Tick(float dt)
{ // Declare Variables
  //--------------------------------------------------
  
  int intVelocityIterations = 8;
  int intPositionIterations = 3;
  
  poWorld->Step(dt, intVelocityIterations, intPositionIterations);
  
  for(auto oBody = poWorld->GetBodyList(); oBody; oBody = oBody->GetNext())
  {
    if(oBody->GetUserData() != NULL)
    {
      auto oItem = (Sprite *) oBody->GetUserData();
      oItem->setPosition(Point(oBody->GetPosition().x, oBody->GetPosition().y));
      oItem->setRotation(-1 * CC_RADIANS_TO_DEGREES(oBody->GetAngle()));
      
      if(oItem->getPositionY() < - WORLD_TO_SCREEN(1) ||
         oItem->getPositionX() < - WORLD_TO_SCREEN(1) ||
         oItem->getPositionX() > Director::getInstance()->getVisibleSize().width + WORLD_TO_SCREEN(1))
      {
        removeChild(oItem);
        poWorld->DestroyBody(oBody);
      }
    }
  }
  
  //--------------------------------------------------
} // End of Tick Method


//============================================================================
bool MainScene::TouchBegan(Touch *poTouch, Event *poEvent)
{ // Declare Variables
  //--------------------------------------------------
  
  CreateDice(poTouch->getLocation());
  
  return true;
  
  //--------------------------------------------------
} // End of TouchBegan Method


//============================================================================
void MainScene::PlayButtonClick()
{ // Declare Variables
  //--------------------------------------------------
  
  CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Button Press.mp3");
  CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(.1);
  
  //--------------------------------------------------
} // End of PlayButtonClick Method


//============================================================================
void MainScene::menuExitCallback(Object* pSender)
{ // Declare Variables
  //--------------------------------------------------
  
  CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
  Director::getInstance()->popScene();
  PlayButtonClick();
  
  //--------------------------------------------------
} // End of menuExitCallback Method


//============================================================================
void MainScene::menuSevenCallback(Object* pSender)
{ // Declare Variables
  //--------------------------------------------------
  
  m_eBidType = SevenBid;
  m_BidLabel->setString(RtnBidTextString(SevenBid));
  PlayButtonClick();
  
  //--------------------------------------------------
} // End of menuSevenCallback Method


//============================================================================
void MainScene::menuOddCallback(Object* pSender)
{ // Declare Variables
  //--------------------------------------------------
  
  m_eBidType = OddBid;
  m_BidLabel->setString(RtnBidTextString(OddBid));
  PlayButtonClick();
  
  //--------------------------------------------------
} // End of menuOddCallback Method


//============================================================================
void MainScene::menuEvenCallback(Object* pSender)
{ // Declare Variables
  //--------------------------------------------------
  
  m_eBidType = EvenBid;
  m_BidLabel->setString(RtnBidTextString(EvenBid));
  PlayButtonClick();
  
  //--------------------------------------------------
} // End of menuEvenCallback Method


//============================================================================
void MainScene::menuRollCallback(Object* pSender)
{ // Declare Variables
  //--------------------------------------------------
  
  if(m_eStatusType == Winner)
  {
    m_eStatusType = Loser;
    m_StatusLabel->setString(RtnStatusTextString(m_eStatusType));
  }
  else
  {
    m_eStatusType = Winner;
    m_StatusLabel->setString(RtnStatusTextString(m_eStatusType));
  }
  
  PlayButtonClick();
  
  //--------------------------------------------------
} // End of menuRollCallback Method



