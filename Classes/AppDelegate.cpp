

#include "AppDelegate.h"
#include "HomeScene.h"
#include "MainScene.h"

USING_NS_CC;


//============================================================================
AppDelegate::AppDelegate()
{ // Declare Variables
  //--------------------------------------------------
  
  
  
  //--------------------------------------------------
} // End of AppDelegate Method


//============================================================================
AppDelegate::~AppDelegate()
{ // Declare Variables
  //--------------------------------------------------
  
  
  
  //--------------------------------------------------
} // End of ~AppDelegate Method


//============================================================================
bool AppDelegate::applicationDidFinishLaunching()
{ // Declare Variables
  //--------------------------------------------------
  
    // initialize director
    auto director = Director::getInstance();
    auto eglView = EGLView::getInstance();

    director->setOpenGLView(eglView);
	
    // turn on display FPS
    director->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    auto scene = HomeScene::createScene();

    // run
    director->runWithScene(scene);

    return true;
  
  //--------------------------------------------------
} // End of applicationDidFinishLaunching Method


//============================================================================
void AppDelegate::applicationDidEnterBackground()
{ // This function will be called when the app is inactive.
  // When comes a phone call,it's be invoked too
  //--------------------------------------------------
  
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
  
  //--------------------------------------------------
} // End of applicationDidEnterBackground Method


//============================================================================
void AppDelegate::applicationWillEnterForeground()
{ // this function will be called when the app is active again
  //--------------------------------------------------
  
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
  
  //--------------------------------------------------
} // End of applicationWillEnterForeground Method








