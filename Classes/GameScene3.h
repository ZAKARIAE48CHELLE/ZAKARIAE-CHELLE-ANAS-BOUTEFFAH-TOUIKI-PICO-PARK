#ifndef __GAME_SCENE3_H__
#define __GAME_SCENE3_H__

#include "cocos2d.h"

class GameScene3 : public cocos2d::Layer
{
public:
  
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene3);
private :
    void setPhysicsWorld(cocos2d::PhysicsWorld* world) { sceneworld = world; };
    cocos2d::PhysicsWorld* sceneworld;
    
};

#endif // __GAME_SCENE3_H__
