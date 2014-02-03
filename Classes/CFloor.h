//
//  CFloor.h
//  Under-n-Over
//
//  Created by Paul Cefalu on 2/2/14.
//
//

#ifndef __Under_n_Over__CFloor__
#define __Under_n_Over__CFloor__

#include "SimpleAudioEngine.h"
#include "Box2D/Box2D.h"
#include "CPhysicsBody.h"
#include "cocos2d.h"

using namespace cocos2d;


//****************************************************************************
class CFloor : public CPhysicsBody
{ // Class Data Members
  //--------------------------------------------------
private:
  void TemplateMethod();
  
  
  
public:
  CFloor();
  CFloor(b2World *poWorld, b2Vec2 *poGravity, CPhysicsBody::eShapeTypes eType,
         Point *poPosition, CPhysicsBody::eBodyTypes eBody, float sngScale, std::string strImage);
  
  ~CFloor();
  
  
  //--------------------------------------------------
};// End of CFloor Class


#endif /* defined(__Under_n_Over__CFloor__) */
