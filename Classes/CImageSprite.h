//
//  CImageSprite.h
//  Under-n-Over
//
//  Created by Paul Cefalu on 2/2/14.
//
//

#ifndef __Under_n_Over__CImageSprite__
#define __Under_n_Over__CImageSprite__

#include "SimpleAudioEngine.h"
#include "Box2D/Box2D.h"
#include "CPhysicsBody.h"
#include "cocos2d.h"

using namespace cocos2d;


//****************************************************************************
class CImageSprite : public CPhysicsBody
{ // Class Data Members
  //--------------------------------------------------
private:
  void TemplateMethod();
  
  
  
public:
  CImageSprite();
  CImageSprite(b2World *poWorld, b2Vec2 *poGravity, CPhysicsBody::eShapeTypes eType,
         Point *poPosition, CPhysicsBody::eBodyTypes eBody, float sngScale, std::string strImage);
  
  ~CImageSprite();
  
  enum eImageIDs
  { // Image IDs
    //--------------
    UN_ASSIGNED_IMAGE_ID,
    DICE_IMAGE_1_ID,
    DICE_IMAGE_2_ID,
    DICE_IMAGE_3_ID,
    DICE_IMAGE_4_ID,
    DICE_IMAGE_5_ID,
    DICE_IMAGE_6_ID
  };
  
  void SetImage(eImageIDs eTypeID);
  void Visible(bool bState);
  
  //--------------------------------------------------
};// End of CImageSprite Class


#endif /* defined(__Under_n_Over__CImageSprite__) */
