//
//  MainScene.cpp
//  Under-n-Over
//
//  Created by Paul Cefalu on 1/30/14.
//
//
#include <iostream>

#include "MscConstants.h"
#include "MainScene.h"


//b2World  *poWorld;
//b2Vec2    oGravity;


//============================================================================
MainScene::MainScene()
{ // Declare Variables
  //--------------------------------------------------
  

  
  //--------------------------------------------------
} // End of Constructor Method


//============================================================================
MainScene::~MainScene()
{ // Declare Variables
  //--------------------------------------------------
  
//  if(m_poDice_1   != nullptr) delete m_poDice_1;
//  if(m_poDice_2   != nullptr) delete m_poDice_2;
  if(m_poFloor    != nullptr) delete m_poFloor;
  if(m_poBoundry  != nullptr) delete m_poBoundry;
  if(m_poImage_1  != NULL)    delete m_poImage_1;
  if(m_poImage_2  != NULL)    delete m_poImage_2;
  if(m_poWorld    != NULL)    delete m_poWorld;
  
//  m_poDice_1   = nullptr;
//  m_poDice_2   = nullptr;
  m_poFloor    = nullptr;
  m_poBoundry  = nullptr;
  m_poImage_1  = nullptr;
  m_poImage_2  = nullptr;
  m_poWorld    = nullptr;

  //--------------------------------------------------
} // End of Destructor Method


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
  
  Size visibleSize  = Director::getInstance()->getVisibleSize();
  Point origin      = Director::getInstance()->getVisibleOrigin();
  
  
  // Create Physics World
  //--------------------------------------------------
  m_poGravity    = new b2Vec2(0.0f, -WORLD_TO_SCREEN(GRAVITY_RATIO));
  bool bDoSleep  = true;
  
  m_poWorld = new b2World(*m_poGravity);
  m_poWorld->SetAllowSleeping(bDoSleep);
  
  
  // Create Static Body Floor
  //--------------------------------------------------
  Point *poPoint  = new Point(origin.x + 575, origin.y + 150);
  m_poFloor       = new CFloor(m_poWorld, m_poGravity, CFloor::eShapeTypes::EDGE_SHAPE,
                               poPoint, CFloor::eBodyTypes::STATIC_BODY, .35, "Floor.png");
  
  this->addChild(m_poFloor->SpriteComponent(), 0);

  
  // Create Static Body Boundry
  //--------------------------------------------------
  sngHorzSkew                = visibleSize.width/2;
  sngVertSkew                = visibleSize.height/2;

  auto *poBoundry            = Sprite::create("Button.png");
  poBoundry->setPosition(Point(origin.x + sngHorzSkew, origin.y + 150));
  poBoundry->setScale(.05);
  
  b2BodyDef oBoundryBodyDef;
  oBoundryBodyDef.type      = b2_staticBody;
  oBoundryBodyDef.position  = b2Vec2(origin.x + sngHorzSkew, origin.y + 150);
  oBoundryBodyDef.userData  = poBoundry;
  
  b2Body *poBoundryBody     = m_poWorld->CreateBody(&oBoundryBodyDef);
  
  b2EdgeShape  oBoundryEdge;
  oBoundryEdge.Set(b2Vec2(origin.x - 275, origin.y + 25), b2Vec2(sngHorzSkew - 300, origin.y + 25));
  
  b2FixtureDef oBoundryFixture;
  oBoundryFixture.density      = DEFAULT_FIXTURE_DENSITY;
  oBoundryFixture.friction     = DEFAULT_FIXTURE_FICTION;
  oBoundryFixture.restitution  = DEFAULT_FIXTURE_RESTITUTION;
  oBoundryFixture.shape        = &oBoundryEdge;
  
  poBoundryBody->CreateFixture(&oBoundryFixture);
  
  this->addChild(poBoundry, 0);

  
  // Create Image Objects
  //--------------------------------------------------
  auto poGravity  = (b2Vec2 *) new b2Vec2(0.0f, -WORLD_TO_SCREEN(GRAVITY_RATIO));
  bool bSleep     = true;
  
  auto poWorld    = (b2World *) new b2World(*poGravity);
  poWorld->SetAllowSleeping(bSleep);
  
  sngHorzSkew                = visibleSize.width/2;
  sngVertSkew                = visibleSize.height/2;
  
  Point *poImgPoint1  = new Point(origin.x + sngHorzSkew - 55, origin.y + 200);
  m_poImage_1         = new CImageSprite(poWorld, poGravity, CImageSprite::eShapeTypes::CIRCLE_SHAPE,
                                         poImgPoint1, CImageSprite::eBodyTypes::STATIC_BODY, .5, "D_3.png");
  
  this->addChild(m_poImage_1->SpriteComponent(), 0);
  
  Point *poImgPoint2  = new Point(origin.x + sngHorzSkew + 55, origin.y + 200);
  m_poImage_2         = new CImageSprite(poWorld, poGravity, CImageSprite::eShapeTypes::CIRCLE_SHAPE,
                                         poImgPoint2, CImageSprite::eBodyTypes::STATIC_BODY, .5, "D_4.png");
  
  this->addChild(m_poImage_2->SpriteComponent(), 0);
  
  
  // Create Status Label
  //--------------------------------------------------
  auto StatusLabel = LabelTTF::create(RtnStatusTextString(Inactive), "Arial", 60);
  sngHorzSkew      = visibleSize.width/2;
  sngVertSkew      = visibleSize.height - StatusLabel->getContentSize().height;
  
  StatusLabel->setPosition(Point(origin.x + sngHorzSkew, origin.y + sngVertSkew));
  this->addChild(StatusLabel, 1, m_StatusTagID);
  
  
  // Create Bid Label
  //--------------------------------------------------
  auto BidLabel  = LabelTTF::create(RtnBidTextString(NoBid), "Arial", 36);
  sngHorzSkew    = BidLabel->getContentSize().width/2 + 10 + (visibleSize.width - BidLabel->getContentSize().width)/2;
  sngVertSkew    = BidLabel->getContentSize().height/2;

  BidLabel->setPosition(Point(origin.x + sngHorzSkew, origin.y + sngVertSkew + 90));
  this->addChild(BidLabel, 1, m_BidTagID);
  
  
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
  
  
  // Configure Background Music
  //--------------------------------------------------
  CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Music Loop.mp3");
  CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Music Loop.mp3", true);
  CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(.03);
  
  
  // Create and Configure Physics
  //--------------------------------------------------
  auto poTouchListener           = EventListenerTouchOneByOne::create();
  poTouchListener->onTouchBegan  = CC_CALLBACK_2(MainScene::TouchBegan, this);
  getEventDispatcher()->addEventListenerWithFixedPriority(poTouchListener, 100);
  
  schedule(schedule_selector(MainScene::Tick));
  
  return true;
  
  //--------------------------------------------------
} // End of init Method


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
void MainScene::UpdateStatusDisplay(eStatusTypes eType)
{ // Declare Variables
  //--------------------------------------------------
  
  LabelTTF *poStatusLabel  = (LabelTTF *)this->getChildByTag(m_StatusTagID);
  m_eStatusType            = eType;
  
  poStatusLabel->setString(RtnStatusTextString(m_eStatusType));
  
  //--------------------------------------------------
} // End of UpdateStatusDisplay Method


//============================================================================
void MainScene::Tick(float dt)
{ // Declare Variables
  //--------------------------------------------------
  
  if(m_bDisableRolls)
  {
    m_poWorld->Step(dt, DEFAULT_VELOCITY_ITERATIONS, DEFAULT_POSITION_ITERATIONS);
    
    for(auto oBody = m_poWorld->GetBodyList(); oBody; oBody = oBody->GetNext())
    {
      if(oBody->GetUserData() != NULL)
      { // Perform Processing Operation
        //----------------------------------------------
        auto oItem = (Sprite *) oBody->GetUserData();
        
        float   sngLocX    = oBody->GetPosition().x;
        float   sngLocY    = oBody->GetPosition().y;
        
        oItem->setPosition(Point(sngLocX, sngLocY));
        oItem->setRotation(-5 * CC_RADIANS_TO_DEGREES(oBody->GetAngle()));
        
        if(oItem->getPositionY() < - WORLD_TO_SCREEN(1) ||
           oItem->getPositionX() < - WORLD_TO_SCREEN(1) ||
           oItem->getPositionX() > Director::getInstance()->getVisibleSize().width + WORLD_TO_SCREEN(1))
        {
          removeChild(oItem);
          m_poWorld->DestroyBody(oBody);
          m_DiceHaveFallen++;

        }
      }
    }

    if(m_DiceHaveFallen >= 2)
    {
      ProcessStatusInformation();
      m_bDisableRolls = false;
    }
  }
  
  //--------------------------------------------------
} // End of Tick Method


//============================================================================
void MainScene::ProcessStatusInformation()
{ // Declare Variables
  //--------------------------------------------------
  
  StopRollingSound();
  
  int intLookupID_1 = arc4random_uniform(m_MaxLimitDice);
  if(intLookupID_1 == 0) intLookupID_1 = 1;
  
  int intLookupID_2 = arc4random_uniform(m_MaxLimitDice);
  if(intLookupID_2 == 0) intLookupID_2 = 1;

  m_poImage_1->SetImage((CImageSprite::eImageIDs) intLookupID_1);
  m_poImage_2->SetImage((CImageSprite::eImageIDs) intLookupID_2);
  
  int intResult = intLookupID_1 + intLookupID_2;
  
  if(m_eBidType == OddBid)
  { // Process Status for ODD Bid
    //--------------------------------------------------
    if(intResult == 3 || intResult == 5 || intResult == 9 || intResult == 11)
    {
      UpdateStatusDisplay(Winner);
      PlayWinnerSound();
    }
    else
    {
      UpdateStatusDisplay(Loser);
      PlaySorrySound();
    }
  }
  
  if(m_eBidType == EvenBid)
  { // Process Status for EVEN Bid
    //--------------------------------------------------
    if(intResult == 2 || intResult == 4 || intResult == 6 || intResult == 8 || intResult == 10 || intResult == 12)
    {
      UpdateStatusDisplay(Winner);
      PlayWinnerSound();
    }
    else
    {
      UpdateStatusDisplay(Loser);
      PlaySorrySound();
    }
  }
  
  if(m_eBidType == SevenBid)
  { // Process Status for SEVEN Bid
    //--------------------------------------------------
    if(intResult == 7)
    {
      UpdateStatusDisplay(Winner);
      PlayWinnerSound();
    }
    else
    {
      UpdateStatusDisplay(Loser);
      PlaySorrySound();
    }
  }
  
  m_poImage_1->Visible(true);
  m_poImage_2->Visible(true);
  
  //--------------------------------------------------
} // End of ProcessStatusInformation Method


//============================================================================
bool MainScene::TouchBegan(Touch *poTouch, Event *poEvent)
{ // Declare Variables
  //--------------------------------------------------
  
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
void MainScene::PlayWinnerSound()
{ // Declare Variables
  //--------------------------------------------------
  
  CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Happy Sound.mp3");
  CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(.5);
  
  //--------------------------------------------------
} // End of PlayWinnerSound Method


//============================================================================
void MainScene::PlaySorrySound()
{ // Declare Variables
  //--------------------------------------------------
  
  CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sorry Sound.wav");
  CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(.8);
  
  //--------------------------------------------------
} // End of PlaySorrySound Method


//============================================================================
void MainScene::PlayRollingSound()
{ // Declare Variables
  //--------------------------------------------------
  
  CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Dice Rolling.wav");
  CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(1);
  
  //--------------------------------------------------
} // End of PlayRollingSound Method


//============================================================================
void MainScene::StopRollingSound()
{ // Declare Variables
  //--------------------------------------------------
  
  CocosDenshion::SimpleAudioEngine::getInstance()->stopAllEffects();
  
  //--------------------------------------------------
} // End of StopRollingSound Method


//============================================================================
void MainScene::menuExitCallback(Object *pSender)
{ // Declare Variables
  //--------------------------------------------------
  
  PlayButtonClick();
  CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
  Director::getInstance()->popScene();
  
  //--------------------------------------------------
} // End of menuExitCallback Method


//============================================================================
void MainScene::menuSevenCallback(Object *pSender)
{ // Declare Variables
  //--------------------------------------------------
  
  if(!m_bDisableRolls)
  {
    PlayButtonClick();
    LabelTTF *poBidLabel = (LabelTTF *)this->getChildByTag(m_BidTagID);

    m_eBidType = SevenBid;
    poBidLabel->setString(RtnBidTextString(SevenBid));
  }
  
  //--------------------------------------------------
} // End of menuSevenCallback Method


//============================================================================
void MainScene::menuOddCallback(Object *pSender)
{ // Declare Variables
  //--------------------------------------------------
  
  if(!m_bDisableRolls)
  {
    PlayButtonClick();
    LabelTTF *poBidLabel = (LabelTTF *)this->getChildByTag(m_BidTagID);
    
    m_eBidType = OddBid;
    poBidLabel->setString(RtnBidTextString(OddBid));
  }
  
  //--------------------------------------------------
} // End of menuOddCallback Method


//============================================================================
void MainScene::menuEvenCallback(Object *pSender)
{ // Declare Variables
  //--------------------------------------------------
  
  if(!m_bDisableRolls)
  {
    PlayButtonClick();
    LabelTTF *poBidLabel = (LabelTTF *)this->getChildByTag(m_BidTagID);
    
    m_eBidType = EvenBid;
    poBidLabel->setString(RtnBidTextString(EvenBid));
  }
  
  //--------------------------------------------------
} // End of menuEvenCallback Method


//============================================================================
void MainScene::menuRollCallback(Object *pSender)
{ // Declare Variables
  //--------------------------------------------------
  
  if(!m_bDisableRolls)
  { // Dice_1
    //------------------------------------------------
    m_poImage_1->Visible(false);
    m_poImage_2->Visible(false);
    
    float sngHorzSkew = 0;
    float sngVertSkew = 0;
    
    Size visibleSize  = Director::getInstance()->getVisibleSize();
    Point origin      = Director::getInstance()->getVisibleOrigin();
    
    sngHorzSkew      = visibleSize.width/2;
    sngVertSkew      = visibleSize.height/2;
    
    Point *poPoint1  = new Point(origin.x - 50 + sngHorzSkew, origin.y + sngVertSkew + 15);
    auto poDice_1    = (CDice *) new CDice(m_poWorld, m_poGravity, CDice::eShapeTypes::CIRCLE_SHAPE,
                                           poPoint1, CDice::eBodyTypes::DYNAMIC_BODY, .5, "Smile Dice.png");
    
    this->addChild(poDice_1->SpriteComponent(), 0);
    
    b2Body *poBody1  = poDice_1->Body();
    b2Vec2 force1    = b2Vec2(-100, 100);
    poBody1->ApplyLinearImpulse(force1, poBody1->GetPosition(), true);
    
    
    // Dice_2
    //------------------------------------------------
    sngHorzSkew      = visibleSize.width/2;
    sngVertSkew      = visibleSize.height/2;
    
    Point *poPoint2  = new Point(origin.x - 5 + sngHorzSkew, origin.y + sngVertSkew + 135);
    auto poDice_2    = (CDice *) new CDice(m_poWorld, m_poGravity, CDice::eShapeTypes::CIRCLE_SHAPE,
                                           poPoint2, CDice::eBodyTypes::DYNAMIC_BODY, .5, "Sad Dice.png");
    
    this->addChild(poDice_2->SpriteComponent(), 0);
    
    b2Body *poBody2  = poDice_2->Body();
    b2Vec2 force2    = b2Vec2(-100, 100);
    poBody2->ApplyLinearImpulse(force2, poBody2->GetPosition(), true);
    
    m_NumberOfDice    = 0;
    m_DiceHaveFallen  = 0;
    m_bDisableRolls   = true;
    
    UpdateStatusDisplay(Inactive);
    PlayRollingSound();
    PlayButtonClick();
  }
  
  //--------------------------------------------------
} // End of menuRollCallback Method



