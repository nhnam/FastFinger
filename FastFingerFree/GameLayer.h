//
//  GameLayer.h
//  FastFingerFree
//
//  Created by Nam Nguyen on 7/9/13.
//
//

#ifndef __FastFingerFree__GameLayer__
#define __FastFingerFree__GameLayer__

#include <iostream>
#include "cocos2d.h"
class GameLayerScene:public cocos2d::CCLayer{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    void menuCloseCallback(CCObject* pSender);
    void tick(float dt);
    void spriteTick(float dt);
    CREATE_FUNC(GameLayerScene);
    virtual void ccTouchesBegan(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    virtual void ccTouchesMoved(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    virtual void ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
private:
    cocos2d::CCArray* arrSprites;
    float curSpeed;
    int curStep;
    float curScore;
    float curTimer;
};
#endif /* defined(__FastFingerFree__GameLayer__) */
