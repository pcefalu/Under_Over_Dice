//
//  CPhysicsBody.cpp
//  Under-n-Over
//
//  Created by Paul Cefalu on 2/1/14.
//
//
#include <iostream>

#include "MscConstants.h"
#include "CPhysicsBody.h"


//============================================================================
void CPhysicsBody::TemplateMethod()
{ // Declare Variables
  //--------------------------------------------------
  
  
  
  //--------------------------------------------------
} // End of xxx Method


//============================================================================
CPhysicsBody::CPhysicsBody()
{ // Declare Variables
  //--------------------------------------------------

  
  
  //--------------------------------------------------
} // End of Constructor Method


//============================================================================
CPhysicsBody::~CPhysicsBody()
{ // Declare Variables
  //--------------------------------------------------


  
  //--------------------------------------------------
} // End of Destructor Method


//============================================================================
void CPhysicsBody::InitialComponent(b2World *poWorld, b2Vec2 *poGravity, eShapeTypes eType, Point *poPosition,
                                    eBodyTypes eBody, float sngScale, std::string strImage)
{ // Declare Variables
  //--------------------------------------------------
  
  m_poWorld    = poWorld;
  m_poGravity  = poGravity;
  
  m_poSprite   = Sprite::create(strImage);
  m_poSprite->setPosition(*poPosition);
  m_poSprite->setScale(sngScale);
  
  switch(eBody)
  {
    case STATIC_BODY:
      m_oBodyDef.type = b2_staticBody;
      break;
      
    case DYNAMIC_BODY:
      m_oBodyDef.type = b2_dynamicBody;
      break;
      
    case UN_ASSIGNED_BODY:
    default:
      m_oBodyDef.type = b2_staticBody;
      break;
  }
  
  m_oBodyDef.position  = b2Vec2(poPosition->x, poPosition->y);
  m_oBodyDef.userData  = m_poSprite;
  
  m_poBody             = m_poWorld->CreateBody(&m_oBodyDef);
  
  switch(eType)
  {
    case CIRCLE_SHAPE:
    { // Configure Circle Object
      //----------------------------------------------
      b2CircleShape oCircle;
      oCircle.m_radius     = WORLD_TO_SCREEN(DEFAULT_RADIUS_VALUE);
      m_oFixtureDef.shape  = &oCircle;
      m_poShape            = &oCircle;
      break;
    }
      
    case EDGE_SHAPE:
    { // Configure edge Object
      //----------------------------------------------
      b2EdgeShape oEdge;
      oEdge.Set(b2Vec2(0,0), b2Vec2(WORLD_TO_SCREEN(DEFAULT_RADIUS_VALUE), 0));
      m_oFixtureDef.shape  = &oEdge;
      m_poShape            = &oEdge;
      break;
    }
      
    case CHAIN_SHAPE:
    { // Configure chain Object
      //----------------------------------------------
      b2ChainShape oChain;
      m_oFixtureDef.shape  = &oChain;
      m_poShape            = &oChain;
      break;
    }
      
    case POLYGON_SHAPE:
    { // Configure Polygon Object
      //----------------------------------------------
      b2PolygonShape oPolygon;
      m_oFixtureDef.shape  = &oPolygon;
      m_poShape            = &oPolygon;
      break;
    }
      
    case UN_ASSIGNED_SHAPE:
    default:
    { // Configure Default Object
      //----------------------------------------------
      b2PolygonShape oPolygon;
      m_oFixtureDef.shape  = &oPolygon;
      m_poShape            = &oPolygon;
      break;
    }
  }
  
  m_oFixtureDef.density      = DEFAULT_DENSITY;
  m_oFixtureDef.friction     = DEFAULT_FICTION;
  m_oFixtureDef.restitution  = DEFAULT_RESTITUTION;
  
  m_poBody->CreateFixture(&m_oFixtureDef);
  
  //--------------------------------------------------
} // End of InitialComponent Method


//============================================================================
void CPhysicsBody::SetImage(std::string *pstrFileName)
{ // Declare Variables
  //--------------------------------------------------
  
  m_poSprite->setTexture(*pstrFileName);
  
  //--------------------------------------------------
} // End of SetImage Method


//============================================================================
void CPhysicsBody::Visible(bool bState)
{ // Declare Variables
  //--------------------------------------------------
  
  m_poSprite->setVisible(bState);
  
  //--------------------------------------------------
} // End of Visible Method


//============================================================================
void CPhysicsBody::UpdateFixtureInfo()
{ // Declare Variables
  //--------------------------------------------------
  
  m_poBody->CreateFixture(&m_oFixtureDef);
  
  //--------------------------------------------------
} // End of UpdateFixtureInfo Method


//============================================================================
void CPhysicsBody::SetFriction(float sngValue)
{ // Declare Variables
  //--------------------------------------------------
  
  m_oFixtureDef.friction = sngValue;
  
  //--------------------------------------------------
} // End of SetFriction Method


//============================================================================
void CPhysicsBody::SetDensity(float sngValue)
{ // Declare Variables
  //--------------------------------------------------
  
  m_oFixtureDef.density = sngValue;
  
  //--------------------------------------------------
} // End of SetDensity Method


//============================================================================
void CPhysicsBody::SetRestitution(float sngValue)
{ // Declare Variables
  //--------------------------------------------------
  
  m_oFixtureDef.restitution = sngValue;
  
  //--------------------------------------------------
} // End of SetRestitution Method


//============================================================================
float CPhysicsBody::GetDensity()
{ // Declare Variables
  //--------------------------------------------------
  
  return m_oFixtureDef.density;
  
  //--------------------------------------------------
} // End of GetDensity Method


//============================================================================
float CPhysicsBody::GetFriction()
{ // Declare Variables
  //--------------------------------------------------
  
  return m_oFixtureDef.friction;
  
  //--------------------------------------------------
} // End of GetFriction Method


//============================================================================
float CPhysicsBody::GetRestitution()
{ // Declare Variables
  //--------------------------------------------------
  
  return m_oFixtureDef.restitution;
  
  //--------------------------------------------------
} // End of GetRestitution Method


//============================================================================
b2Vec2 *CPhysicsBody::Gravity()
{ // Declare Variables
  //--------------------------------------------------
  
  return m_poGravity;
  
  //--------------------------------------------------
} // End of Gravity Method


//============================================================================
b2BodyDef *CPhysicsBody::BodyDef()
{ // Declare Variables
  //--------------------------------------------------
  
  return &m_oBodyDef;
  
  //--------------------------------------------------
} // End of BodyDef Method


//============================================================================
b2FixtureDef *CPhysicsBody::FixtureDef()
{ // Declare Variables
  //--------------------------------------------------
  
  return &m_oFixtureDef;
  
  //--------------------------------------------------
} // End of FixtureDef Method


//============================================================================
b2World *CPhysicsBody::World()
{ // Declare Variables
  //--------------------------------------------------
  
  return m_poWorld;
  
  //--------------------------------------------------
} // End of World Method


//============================================================================
b2Body *CPhysicsBody::Body()
{ // Declare Variables
  //--------------------------------------------------
  
  return m_poBody;
  
  //--------------------------------------------------
} // End of Body Method


//============================================================================
Sprite *CPhysicsBody::SpriteComponent()
{ // Declare Variables
  //--------------------------------------------------
  
  return m_poSprite;
  
  //--------------------------------------------------
} // End of SpriteComponent Method


//============================================================================
b2Shape *CPhysicsBody::BodyShape()
{ // Declare Variables
  //--------------------------------------------------
  
  return m_poShape;
  
  //--------------------------------------------------
} // End of BodyShape Method









