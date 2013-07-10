//
//  GameLayer.cpp
//  FastFingerFree
//
//  Created by Nam Nguyen on 7/9/13.
//
//

#include "GameLayer.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

bool GameLayerScene::init(){
    if(!CCLayer::init()) return false;
    this->setTouchEnabled(true);
    // ask director the window size
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCParticleSystemQuad* m_emitter = new CCParticleSystemQuad();
    m_emitter = CCParticleFire::create();
    m_emitter->setPosition(ccp(size.width/2, size.height/2) );
    this->addChild(m_emitter);
    
    arrSprites = CCArray::create();// autorelease
    curScore = 0;
    curSpeed = 0;
    curStep = 0;
    curTimer = 0;
    
    // schedule timertick:
    schedule(schedule_selector(GameLayerScene::tick));
    // schedule add sprites to scene:
    
    return true;
}
CCScene* GameLayerScene::scene(){
    CCScene *scene = NULL;
    do{
        scene = CCScene::create();// autorelease
        CC_BREAK_IF(!scene);
        GameLayerScene *layer = GameLayerScene::create();
        CC_BREAK_IF(!layer);
        scene->addChild(layer);
    }while(0);
    return scene;
}
void GameLayerScene::menuCloseCallback(CCObject* pSender){
    CCLOG("");
}
void GameLayerScene::tick(float dt){
//    CCLOG("Gamer tick");
    float dx = 0;
    float dy = 0;
    cocos2d::CCSprite* spr = NULL;
    cocos2d::CCPoint position;
    for (int i= 0; i< arrSprites->count(); i++) {
        spr = (CCSprite*)arrSprites->objectAtIndex(i);
        dy = dt*10;
        position = spr->getPosition();
        position.y -= dy;
        spr->setPosition(position);
    }
}

void GameLayerScene::ccTouchesBegan(cocos2d::CCSet* touches, cocos2d::CCEvent* event){}
void GameLayerScene::ccTouchesMoved(cocos2d::CCSet* touches, cocos2d::CCEvent* event){}
void GameLayerScene::ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event){
    CCLOG("Touches..");
    CCTouch *myTouch = (CCTouch *)touches->anyObject();
    CCPoint location = myTouch->getLocationInView();
    location = CCDirector::sharedDirector()->convertToGL(location);
    CCParticleSystemQuad* m_emitter = new CCParticleSystemQuad();
    m_emitter = CCParticleFire::create();
    m_emitter->setPosition(location);
    this->addChild(m_emitter);
}