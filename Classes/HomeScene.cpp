//
//  HomeScene.cpp
//  Under-n-Over
//
//  Created by Paul Cefalu on 1/30/14.
//
//
#include <SimpleAudioEngine.h>
//#include <Box2D/Box2D.h>
#include <iostream>

#include "MscConstants.h"
#include "MainScene.h"
#include "HomeScene.h"

USING_NS_CC;


//============================================================================
Scene* HomeScene::createScene()
{ // Declare Variables
  //--------------------------------------------------
  
  // 'scene' is an autorelease object
  auto scene = Scene::create();
  
  // 'layer' is an autorelease object
  auto layer = HomeScene::create();

  // add layer as a child to scene
  scene->addChild(layer);
  
  // return the scene
  return scene;
  
  //--------------------------------------------------
} // End of createScene Method


//============================================================================
bool HomeScene::init()
{ // on "init" you need to initialize your instance
  //--------------------------------------------------
  
  if( !LayerColor::initWithColor(Color4B(255, 255, 255, 255)) ) //RGBA
  {
    return false;
  }
  
  Size visibleSize = Director::getInstance()->getVisibleSize();
  Point origin = Director::getInstance()->getVisibleOrigin();
  
  
  // Create Exit Button
  //--------------------------------------------------
  auto ExitItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(HomeScene::menuExitCallback, this));
  
	ExitItem->setPosition(Point(origin.x + visibleSize.width - ExitItem->getContentSize().width/2 ,
                               origin.y + ExitItem->getContentSize().height/2));
  
  auto ExitButton = Menu::create(ExitItem, NULL);
  ExitButton->setPosition(Point::ZERO);
  this->addChild(ExitButton, 1);
  
  
  // Create Play Button
  //--------------------------------------------------
  auto playItem = MenuItemImage::create("Play Button.png", "Play Button.png", CC_CALLBACK_1(HomeScene::menuPlayCallback, this));
  playItem->setScale(.75, .5);

  float sngHorzSkew = playItem->getContentSize().width/2 + 10 + (visibleSize.width - playItem->getContentSize().width)/2;
  float sngVertSkew = playItem->getContentSize().height/2;
	playItem->setPosition(Point(origin.x + sngHorzSkew, origin.y + sngVertSkew));
  
  auto buttonItem = Menu::create(playItem, NULL);
  buttonItem->setPosition(Point::ZERO);
  this->addChild(buttonItem, 1);
  
  
  // Create Background
  //--------------------------------------------------
  auto label = LabelTTF::create("Home Scene", "Arial", 24);
  
  // position the label on the center of the screen
  label->setPosition(Point(origin.x + visibleSize.width/2,
                           origin.y + visibleSize.height - label->getContentSize().height));
  
  // add the label as a child to this layer
  this->addChild(label, 1);
  
  // Create and Configure Background of Scene
  auto sprite = Sprite::create("HomeScene.png");
  
  // position the sprite on the center of the screen
  sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
  sprite->setScale(FULL_SCREEN_HORIZONTAL_SCALE, FULL_SCREEN_VERTICAL_SCALE);
  
  // add the sprite as a child to this layer
  this->addChild(sprite, 0);
  
  return true;
  
  //--------------------------------------------------
} // End of init Method


//============================================================================
void HomeScene::PlayButtonClick()
{ // Declare Variables
  //--------------------------------------------------
  
  CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Button Press.mp3");
  CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(.1);
  
  //--------------------------------------------------
} // End of PlayButtonClick Method


//============================================================================
void HomeScene::menuExitCallback(Object* pSender)
{ // Declare Variables
  //--------------------------------------------------
  
  PlayButtonClick();
  Director::getInstance()->end();
  
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
  exit(0);
#endif
  
  //--------------------------------------------------
} // End of menuExitCallback Method


//============================================================================
void HomeScene::menuPlayCallback(Object* pSender)
{ // Declare Variables
  //--------------------------------------------------
  
  PlayButtonClick();
  Director::getInstance()->pushScene(MainScene::createScene());
  
  //--------------------------------------------------
} // End of menuPlayCallback Method



