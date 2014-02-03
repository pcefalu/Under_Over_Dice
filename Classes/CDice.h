//
//  CDice.h
//  Under-n-Over
//
//  Created by Paul Cefalu on 2/1/14.
//
//

#ifndef __Under_n_Over__CDice__
#define __Under_n_Over__CDice__

#include "SimpleAudioEngine.h"
#include "Box2D/Box2D.h"
#include "CPhysicsBody.h"
#include "cocos2d.h"

using namespace cocos2d;


//****************************************************************************
class CDice : public CPhysicsBody
{ // Class Data Members
  //--------------------------------------------------
private:
  void TemplateMethod();
  
  
  
public:
  CDice();
  CDice(b2World *poWorld, b2Vec2 *poGravity, CPhysicsBody::eShapeTypes eType,
        Point *poPosition, CPhysicsBody::eBodyTypes eBody, float sngScale, std::string strImage);

  ~CDice();
  
  //--------------------------------------------------
};// End of CDice Class


#endif /* defined(__Under_n_Over__CDice__) */
