//
//  CPhysicsBody.h
//  Under-n-Over
//
//  Created by Paul Cefalu on 2/1/14.
//
//

#ifndef __Under_n_Over__CPhysicsBody__
#define __Under_n_Over__CPhysicsBody__

#include "SimpleAudioEngine.h"
#include "Box2D/Box2D.h"
#include "cocos2d.h"

using namespace cocos2d;


//****************************************************************************
class CPhysicsBody : public cocos2d::LayerColor
{ // Class Data Members
  //--------------------------------------------------
private:
  void TemplateMethod();

  b2BodyDef       m_oBodyDef;
  b2FixtureDef    m_oFixtureDef;
  
  b2Vec2         *m_poGravity      = nullptr;
  b2World        *m_poWorld        = nullptr;
  
  b2Shape        *m_poShape        = nullptr;
  b2Body         *m_poBody         = nullptr;
  Sprite         *m_poSprite       = nullptr;
  
  
  
public:
  enum eShapeTypes
  { // Shapes
    //--------------
    UN_ASSIGNED_SHAPE,
    CIRCLE_SHAPE,
    EDGE_SHAPE,
    CHAIN_SHAPE,
    POLYGON_SHAPE
  };
  
  enum eBodyTypes
  { // Bodies
    //--------------
    UN_ASSIGNED_BODY,
    STATIC_BODY,
    DYNAMIC_BODY
  };
  
  enum eIterations
  { // Iteration
    //--------------
    UN_ASSIGNED_VALUE  = 0,
    DEFAULT_VELOCITY   = 8,
    DEFAULT_POSITION   = 3
  };
  
  const float        DEFAULT_SCALE_VALUE     = 1;
  const float        DEFAULT_DENSITY         = 1.0f;
  const float        DEFAULT_FICTION         = 0.6f;
  const float        DEFAULT_RESTITUTION     = 0.8f;
  const float        DEFAULT_RADIUS_VALUE    = 1.0f;
  
  int                VelocityIterations      = DEFAULT_VELOCITY;
  int                PositionIterations      = DEFAULT_POSITION;
  
  const Point        DEFAULT_POINT_POSITION  = Point(10, 10);
  const std::string  DEFAULT_IMAGE           = "Button.png";
  
  
  CPhysicsBody();
  ~CPhysicsBody();
  
  void           InitialComponent(b2World *poWorld, b2Vec2 *poGravity, eShapeTypes eType, Point *poPosition, eBodyTypes eBody, float sngScale, std::string strImage);
  
  b2Vec2        *Gravity();
  b2BodyDef     *BodyDef();
  b2FixtureDef  *FixtureDef();
  b2World       *World();
  b2Body        *Body();
  Sprite        *SpriteComponent();
  b2Shape       *BodyShape();
  
  float GetFriction();
  void  SetFriction(float sngValue);
  
  float GetDensity();
  void  SetDensity(float sngValue);
  
  float GetRestitution();
  void  SetRestitution(float sngValue);
  
  void UpdateFixtureInfo();
  void Visible(bool bState);
  void SetImage(std::string *pstrFileName);
  
  //--------------------------------------------------
};// End of CPhysicsBody Class

#endif /* defined(__Under_n_Over__CPhysicsBody__) */










