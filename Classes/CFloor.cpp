//
//  CFloor.cpp
//  Under-n-Over
//
//  Created by Paul Cefalu on 2/2/14.
//
//
#include <iostream>

#include "MscConstants.h"
#include "CFloor.h"


//============================================================================
void CFloor::TemplateMethod()
{ // Declare Variables
  //--------------------------------------------------
  
  
  
  //--------------------------------------------------
} // End of xxx Method


//============================================================================
CFloor::CFloor()
{ // Declare Variables
  //--------------------------------------------------
  
  Point  *poPosition  = new Point(10, 10);
  
  b2Vec2 *poGravity   = new b2Vec2(0.0f, -WORLD_TO_SCREEN(GRAVITY_RATIO));
  bool    bDoSleep    = true;
  
  b2World *poWorld    = new b2World(*poGravity);
  poWorld->SetAllowSleeping(bDoSleep);
  
  InitialComponent(poWorld, poGravity, EDGE_SHAPE, poPosition, STATIC_BODY, .25, "Floor.png");
  
  //--------------------------------------------------
} // End of Constructor Method


CFloor::CFloor(b2World *poWorld, b2Vec2 *poGravity, CPhysicsBody::eShapeTypes eType,
               Point *poPosition, CPhysicsBody::eBodyTypes eBody, float sngScale, std::string strImage)
{ // Declare Variables
  //--------------------------------------------------
  
  InitialComponent(poWorld, poGravity, eType, poPosition, eBody, sngScale, strImage);
  
  //--------------------------------------------------
} // End of Constructor Method


//============================================================================
CFloor::~CFloor()
{ // Declare Variables
  //--------------------------------------------------
  
  
  
  //--------------------------------------------------
} // End of Destructor Method








