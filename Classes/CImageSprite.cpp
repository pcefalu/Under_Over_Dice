//
//  CImageSprite.cpp
//  Under-n-Over
//
//  Created by Paul Cefalu on 2/2/14.
//
//
#include <iostream>

#include "MscConstants.h"
#include "CImageSprite.h"


//============================================================================
void CImageSprite::TemplateMethod()
{ // Declare Variables
  //--------------------------------------------------
  
  
  
  //--------------------------------------------------
} // End of xxx Method


//============================================================================
CImageSprite::CImageSprite()
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


CImageSprite::CImageSprite(b2World *poWorld, b2Vec2 *poGravity, CPhysicsBody::eShapeTypes eType,
               Point *poPosition, CPhysicsBody::eBodyTypes eBody, float sngScale, std::string strImage)
{ // Declare Variables
  //--------------------------------------------------
  
  InitialComponent(poWorld, poGravity, eType, poPosition, eBody, sngScale, strImage);
  
  //--------------------------------------------------
} // End of Constructor Method


//============================================================================
CImageSprite::~CImageSprite()
{ // Declare Variables
  //--------------------------------------------------
  
  
  
  //--------------------------------------------------
} // End of Destructor Method


//============================================================================
void CImageSprite::SetImage(eImageIDs eTypeID)
{ // Declare Variables
  //--------------------------------------------------
  
  std::string strFileName = "";
  
  switch(eTypeID)
  {
    case DICE_IMAGE_1_ID:
      strFileName = "D_1.png";
      break;
      
    case DICE_IMAGE_2_ID:
      strFileName = "D_2.png";
      break;
      
    case DICE_IMAGE_3_ID:
      strFileName = "D_3.png";
      break;
      
    case DICE_IMAGE_4_ID:
      strFileName = "D_4.png";
      break;
      
    case DICE_IMAGE_5_ID:
      strFileName = "D_5.png";
      break;
      
    case DICE_IMAGE_6_ID:
      strFileName = "D_6.png";
      break;
      
    case UN_ASSIGNED_IMAGE_ID:
    default:
      strFileName = "D_1.png";
      break;
  }

  CPhysicsBody::SetImage(&strFileName);
  
  //--------------------------------------------------
} // End of SetImage Method


//============================================================================
void CImageSprite::Visible(bool bState)
{ // Declare Variables
  //--------------------------------------------------
  
  CPhysicsBody::Visible(bState);
  
  //--------------------------------------------------
} // End of Visible Method






