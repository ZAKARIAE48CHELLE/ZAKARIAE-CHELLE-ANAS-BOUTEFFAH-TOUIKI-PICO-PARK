#ifndef __GAME_SCENE2_H__
#define __GAME_SCENE2_H__

#include "cocos2d.h"

class GameScene2 : public cocos2d::Layer
{
public:
  
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
  
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene2);
private :
    void setPhysicsWorld(cocos2d::PhysicsWorld* world) { sceneworld = world; };
    cocos2d::PhysicsWorld* sceneworld;
    void GoToGameScene3(cocos2d::Ref* sender);
};

#endif // __GAME_SCENE2_H__
