#include "GameScene - 2.h"
#include "GameScene3.h"
#include <png/include/win32/png.h>
#include "GameScene.h"
USING_NS_CC;

Scene* GameScene3::createScene()
{
    // 'scene' is an autorelease object
    //auto scene = Scene::create();
      auto scene = Scene::createWithPhysics();
    PhysicsWorld* world = scene->getPhysicsWorld();
    // 'layer' is an autorelease object
    auto layer = GameScene3::create();
    layer->setPhysicsWorld(scene->getPhysicsWorld());
    // add layer as a child to scene
    scene->addChild(layer);

   

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene3::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto background = Sprite::create("background.jpg");
    auto player = Sprite::create("player.png");
    player->setPosition((Vec2(visibleSize.width * 0.1, visibleSize.height * 0.5)));
    player->setContentSize(CCSize(80, 90));
    player->setName("player");
    auto spriteBody = PhysicsBody::createBox(player->getContentSize() / 1, PhysicsMaterial(0.2f, 0.2f, 0.2f));
    spriteBody->setGravityEnable(true);
    spriteBody->setDynamic(true);
    spriteBody->setContactTestBitmask(1);
    spriteBody->setCollisionBitmask(1);
    spriteBody->setCategoryBitmask(1);
    player->setPhysicsBody(spriteBody);
    this->addChild(player, 3);
    background->setAnchorPoint(Vec2::ZERO);
    background->setPosition(0, 0);
    background->setContentSize(CCSize(5000, 2000));
    this->addChild(background, 2);
    CCRect frame = CCRect(0, 0, 5000, 720);
    auto followplayer = Follow::create(player, frame);
    followplayer->setTarget(player);
    this->runAction(followplayer);

    //changement du stage :
    //landground :
    auto frstground = Sprite::create("box1.png");
    frstground->setPosition(0, 0);
    frstground->setScale(2);
    auto spriteBody0 = PhysicsBody::createBox(frstground->getContentSize() / 1, PhysicsMaterial(1.0f, 1.0f, 1.0f));
    spriteBody0->setGravityEnable(false);
    spriteBody0->setDynamic(false);
    spriteBody0->setContactTestBitmask(1);
    spriteBody0->setCollisionBitmask(1);
    spriteBody0->setCategoryBitmask(1);
    frstground->setRotation(0.0f);
    frstground->setPhysicsBody(spriteBody0);
    this->addChild(frstground, 2);
    //o1
    auto o1 = Sprite::create("small.png");
    o1->setPosition(600, 180);
    o1->setScale(0.7);
    auto spriteBody1 = PhysicsBody::createBox(o1->getContentSize() / 1, PhysicsMaterial(1.0f, 1.0f, 1.0f));
    spriteBody1->setGravityEnable(false);
    spriteBody1->setDynamic(false);
    spriteBody1->setContactTestBitmask(1);
    spriteBody1->setCollisionBitmask(1);
    spriteBody1->setCategoryBitmask(1);
    o1->setRotation(0.0f);
    o1->setPhysicsBody(spriteBody1);
    this->addChild(o1, 2);
    //o2
    auto o2 = Sprite::create("box2.png");
    o2->setPosition(1050, 260);
    o2->setScale(2);
    auto spriteBody2 = PhysicsBody::createBox(o2->getContentSize() / 1, PhysicsMaterial(1.0f, 1.0f, 1.0f));
    spriteBody2->setGravityEnable(false);
    spriteBody2->setDynamic(false);
    spriteBody2->setContactTestBitmask(1);
    spriteBody2->setCollisionBitmask(1);
    spriteBody2->setCategoryBitmask(1);
    o2->setRotation(0.0f);
    o2->setPhysicsBody(spriteBody2);
    this->addChild(o2, 2);
    //o3
    auto o3 = Sprite::create("box2.png");
    o3->setPosition(1300, 260);
    o3->setScale(2);
    auto spriteBody3 = PhysicsBody::createBox(o3->getContentSize() / 1, PhysicsMaterial(1.0f, 1.0f, 1.0f));
    spriteBody3->setGravityEnable(false);
    spriteBody3->setDynamic(false);
    spriteBody3->setContactTestBitmask(1);
    spriteBody3->setCollisionBitmask(1);
    spriteBody3->setCategoryBitmask(1);
    o3->setRotation(0.0f);
    o3->setPhysicsBody(spriteBody3);
    this->addChild(o3, 2);
    //o4
    auto o4 = Sprite::create("box2.png");
    o4->setPosition(1550, 260);
    o4->setScale(2);
    auto spriteBody4 = PhysicsBody::createBox(o4->getContentSize() / 1, PhysicsMaterial(1.0f, 1.0f, 1.0f));
    spriteBody4->setGravityEnable(false);
    spriteBody4->setDynamic(false);
    spriteBody4->setContactTestBitmask(1);
    spriteBody4->setCollisionBitmask(1);
    spriteBody4->setCategoryBitmask(1);
    o4->setRotation(0.0f);
    o4->setPhysicsBody(spriteBody4);
    this->addChild(o4, 2);
    //o4
    auto o5 = Sprite::create("box2.png");
    o5->setScale(2); 
    auto spriteBody5 = PhysicsBody::createBox(o5->getContentSize() / 1, PhysicsMaterial(1.0f, 1.0f, 1.0f));
    spriteBody5->setGravityEnable(false);
    spriteBody5->setDynamic(false);
    spriteBody5->setContactTestBitmask(1);
    spriteBody5->setCollisionBitmask(1);
    spriteBody5->setCategoryBitmask(1);
    o5->setRotation(0.0f);
    o5->setPhysicsBody(spriteBody5);
    this->addChild(o5, 2);
    o5->setPosition(Vec2(2100, 0));
    auto moveAction = MoveTo::create(50, Vec2(2100,800));
    auto repeatAction = RepeatForever::create(moveAction);
    o5->runAction(repeatAction);
    //o6
    auto o6 = Sprite::create("box2.png");
    o6->setPosition(2650, 260);
    o6->setScale(2);
    auto spriteBody6 = PhysicsBody::createBox(o6->getContentSize() / 1, PhysicsMaterial(1.0f, 1.0f, 1.0f));
    spriteBody6->setGravityEnable(false);
    spriteBody6->setDynamic(false);
    spriteBody6->setContactTestBitmask(1);
    spriteBody6->setCollisionBitmask(1);
    spriteBody6->setCategoryBitmask(1);
    o6->setRotation(0.0f);
    o6->setPhysicsBody(spriteBody6);
    this->addChild(o6, 2);
    //o7
    auto o7 = Sprite::create("box2.png");
    o7->setPosition(2850, 260);
    o7->setScale(2);
    auto spriteBody7 = PhysicsBody::createBox(o7->getContentSize() / 1, PhysicsMaterial(1.0f, 1.0f, 1.0f));
    spriteBody7->setGravityEnable(false);
    spriteBody7->setDynamic(false);
    spriteBody7->setContactTestBitmask(1);
    spriteBody7->setCollisionBitmask(1);
    spriteBody7->setCategoryBitmask(1);
    o7->setRotation(0.0f);
    o7->setPhysicsBody(spriteBody7);
    this->addChild(o7, 2);
    //o8
    auto o8 = Sprite::create("box2.png");
    o8->setPosition(3000, 260);
    o8->setScale(2);
    auto spriteBody8 = PhysicsBody::createBox(o8->getContentSize() / 1, PhysicsMaterial(1.0f, 1.0f, 1.0f));
    spriteBody8->setGravityEnable(false);
    spriteBody8->setDynamic(false);
    spriteBody8->setContactTestBitmask(1);
    spriteBody8->setCollisionBitmask(1);
    spriteBody8->setCategoryBitmask(1);
    o8->setRotation(0.0f);
    o8->setPhysicsBody(spriteBody8);
    this->addChild(o8, 2);
    //o9 
    auto o9 = Sprite::create("box2.png");
    o9->setScale(2);
    auto spriteBody9 = PhysicsBody::createBox(o9->getContentSize() / 1, PhysicsMaterial(1.0f, 1.0f, 1.0f));
    spriteBody9->setGravityEnable(false);
    spriteBody9->setDynamic(false);
    spriteBody9->setContactTestBitmask(1);
    spriteBody9->setCollisionBitmask(1);
    spriteBody9->setCategoryBitmask(1);
    o9->setRotation(0.0f);
    o9->setPhysicsBody(spriteBody9);
    this->addChild(o9, 2);
    o9->setPosition(Vec2(3600, 0));
    auto moveAction1 = MoveTo::create(100, Vec2(3600, 800));
    auto repeatAction1 = RepeatForever::create(moveAction1);
    o9->runAction(repeatAction1);
    //o10
    auto o10 = Sprite::create("box2.png");
    o10->setPosition(4100, 260);
    o10->setScale(2);
    auto spriteBody10 = PhysicsBody::createBox(o10->getContentSize() / 1, PhysicsMaterial(1.0f, 1.0f, 1.0f));
    spriteBody10->setGravityEnable(false);
    spriteBody10->setDynamic(false);
    spriteBody10->setContactTestBitmask(1);
    spriteBody10->setCollisionBitmask(1);
    spriteBody10->setCategoryBitmask(1);
    o10->setRotation(0.0f);
    o10->setPhysicsBody(spriteBody10);
    this->addChild(o10, 2);
    //o10
    auto o11 = Sprite::create("box2.png");
    o11->setPosition(4450, 260);
    o11->setScale(2);
    auto spriteBody11 = PhysicsBody::createBox(o11->getContentSize() / 1, PhysicsMaterial(1.0f, 1.0f, 1.0f));
    spriteBody11->setGravityEnable(false);
    spriteBody11->setDynamic(false);
    spriteBody11->setContactTestBitmask(1);
    spriteBody11->setCollisionBitmask(1);
    spriteBody11->setCategoryBitmask(1);
    o11->setRotation(0.0f);
    o11->setPhysicsBody(spriteBody11);
    this->addChild(o11, 2);
    //final :
    auto scdground = Sprite::create("box1.png");
    scdground->setPosition(5000, 0);
    scdground->setScale(2);
    auto spriteBody01 = PhysicsBody::createBox(scdground->getContentSize() / 1, PhysicsMaterial(1.0f, 1.0f, 1.0f));
    spriteBody01->setGravityEnable(false);
    spriteBody01->setDynamic(false);
    spriteBody01->setContactTestBitmask(1);
    spriteBody01->setCollisionBitmask(1);
    spriteBody01->setCategoryBitmask(1);
    scdground->setRotation(0.0f);
    scdground->setPhysicsBody(spriteBody01);
    this->addChild(scdground, 2);







    auto eventListener = EventListenerKeyboard::create();


    eventListener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* player) {

        Vec2 loc = player->getCurrentTarget()->getPosition();
        auto jump = JumpTo::create(1, Point(loc.x + 85, loc.y), 70, 1);
       
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            player->getCurrentTarget()->setPosition(loc.x - 50, loc.y);
            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            player->getCurrentTarget()->setPosition(loc.x + 50, loc.y);
            break;
        case EventKeyboard::KeyCode::KEY_SPACE:
        case EventKeyboard::KeyCode::KEY_W:
            player->getCurrentTarget()->runAction(jump);
            break;
        }
    };

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, player);


    return true;
}
