#include "GameScene - 2.h"
#include <png/include/win32/png.h>
#include "GameScene.h"
using namespace cocos2d::ui;
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
USING_NS_CC_EXT;
#include "GameScene3.h"
#include "Definitions.h"
USING_NS_CC;

Scene* GameScene2::createScene()
{
    // 'scene' is an autorelease object
    //auto scene = Scene::create();
      auto scene = Scene::createWithPhysics();
    PhysicsWorld* world = scene->getPhysicsWorld();
    // 'layer' is an autorelease object
    auto layer = GameScene2::create();
    layer->setPhysicsWorld(scene->getPhysicsWorld());
    // add layer as a child to scene
    scene->addChild(layer);

   

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene2::init()
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
    background->setAnchorPoint(Vec2::ZERO);
    background->setPosition(0, 0);
    background->setContentSize(CCSize(5000, 2000));


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




    auto ground1 = Sprite::create("box1.png");
    ground1->setAnchorPoint(Vec2::ZERO);
    ground1->setPosition(0, 0);
    ground1->setPosition(0, 0);
    ground1->setScale(2);
    ground1->setName("ground1");


    auto spriteBody0 = PhysicsBody::createBox(ground1->getContentSize() / 1, PhysicsMaterial(1.0f, 1.0f, 1.0f));
    spriteBody0->setGravityEnable(false);
    spriteBody0->setDynamic(false);
    spriteBody0->setContactTestBitmask(1);
    spriteBody0->setCollisionBitmask(1);
    spriteBody0->setCategoryBitmask(1);
    ground1->setRotation(0.0f);
    ground1->setPhysicsBody(spriteBody0);
    //obstacle 1
    auto ground2 = Sprite::create("box1.png");
    ground2->setAnchorPoint(Vec2::ZERO);
    ground2->setPosition(600, 0);
    ground2->setPosition(600, 0);
    ground2->setScale(2);
    ground2->setName("ground2");

    auto Push = Label::createWithTTF("Don't Step ", "fonts/Marker Felt.ttf", 30);
    Push->setTextColor(Color4B::RED);
    Push->setPosition(Vec2(350, 320));
    auto panic = Sprite::create("redd.png");
    panic->setScale(0.3);
    panic->setPosition(Vec2(350, 265));

    auto Push1 = Label::createWithTTF("Don't Step ", "fonts/Marker Felt.ttf", 30);
    Push1->setPosition(Vec2(700, 320));
    Push1->setTextColor(Color4B::RED);
    auto panic2 = Sprite::create("redd.png");
    panic2->setScale(0.3);
    panic2->setPosition(Vec2(700, 265));

    auto Push2 = Label::createWithTTF("Don't Step ", "fonts/Marker Felt.ttf", 30);
    Push2->setPosition(Vec2(1050, 320));
    Push2->setTextColor(Color4B::RED);
    auto panic3 = Sprite::create("redd.png");
    panic3->setPosition(Vec2(1050, 265));
    panic3->setScale(0.3);





    auto spriteBody1 = PhysicsBody::createBox(ground2->getContentSize() / 1, PhysicsMaterial(1.0f, 1.0f, 1.0f));
    spriteBody1->setGravityEnable(false);
    spriteBody1->setDynamic(false);
    spriteBody1->setContactTestBitmask(1);
    spriteBody1->setCollisionBitmask(1);
    spriteBody1->setCategoryBitmask(1);
    ground2->setRotation(0.0f);
    ground2->setPhysicsBody(spriteBody1);

    //obstacle 2

    auto obs2 = Sprite::create("box2.png");
    obs2->setPosition(1600, 350);
    obs2->setScale(2);
    auto spriteBody2 = PhysicsBody::createBox(obs2->getContentSize() / 1, PhysicsMaterial(1.0f, 1.0f, 1.0f));
    spriteBody2->setGravityEnable(false);
    spriteBody2->setDynamic(false);
    spriteBody2->setContactTestBitmask(1);
    spriteBody2->setCollisionBitmask(1);
    spriteBody2->setCategoryBitmask(1);
    obs2->setRotation(0.0f);
    obs2->setPhysicsBody(spriteBody2);
    auto Push3 = Label::createWithTTF("Don't Step ", "fonts/Marker Felt.ttf", 30);
    Push3->setPosition(Vec2(1600, 420));
    Push3->setTextColor(Color4B::RED);
    auto panic4 = Sprite::create("redd.png");
    panic4->setPosition(Vec2(1600, 380));
    panic4->setScale(0.3);

    //Obstacle 3
    auto obs3 = Sprite::create("box2.png");
    obs3->setPosition(2000, 500);
    obs3->setScale(2);
    auto spriteBody3 = PhysicsBody::createBox(obs3->getContentSize() / 1, PhysicsMaterial(1.0f, 1.0f, 1.0f));
    spriteBody3->setGravityEnable(false);
    spriteBody3->setDynamic(false);
    spriteBody3->setContactTestBitmask(1);
    spriteBody3->setCollisionBitmask(1);
    spriteBody3->setCategoryBitmask(1);
    obs3->setRotation(0.0f);
    obs3->setPhysicsBody(spriteBody3);
    auto Push4 = Label::createWithTTF("Don't Step ", "fonts/Marker Felt.ttf", 30);
    Push4->setPosition(Vec2(2000, 570));
    Push4->setTextColor(Color4B::RED);
    auto panic5 = Sprite::create("redd.png");
    panic5->setPosition(Vec2(2000, 530));
    panic5->setScale(0.3);
    //obstacle4
    auto obs4 = Sprite::create("box2.png");
    obs4->setPosition(2400, 350);
    obs4->setScale(2);
    auto spriteBody4 = PhysicsBody::createBox(obs4->getContentSize() / 1, PhysicsMaterial(1.0f, 1.0f, 1.0f));
    spriteBody4->setGravityEnable(false);
    spriteBody4->setDynamic(false);
    spriteBody4->setContactTestBitmask(1);
    spriteBody4->setCollisionBitmask(1);
    spriteBody4->setCategoryBitmask(1);
    obs4->setRotation(0.0f);
    obs4->setPhysicsBody(spriteBody4);

    //obstacle5

    auto obs5 = Sprite::create("box2.png");
    obs5->setPosition(2800, 500);
    obs5->setScale(2);
    auto spriteBody5 = PhysicsBody::createBox(obs5->getContentSize() / 1, PhysicsMaterial(1.0f, 1.0f, 1.0f));
    spriteBody5->setGravityEnable(false);
    spriteBody5->setDynamic(false);
    spriteBody5->setContactTestBitmask(1);
    spriteBody5->setCollisionBitmask(1);
    spriteBody5->setCategoryBitmask(1);
    obs5->setRotation(0.0f);
    obs5->setPhysicsBody(spriteBody5);
    auto Push5 = Label::createWithTTF("Don't Step ", "fonts/Marker Felt.ttf", 30);
    Push5->setPosition(Vec2(2800, 570));
    Push5->setTextColor(Color4B::RED);
    auto panic6 = Sprite::create("redd.png");
    panic6->setPosition(Vec2(2800, 530));
    panic6->setScale(0.3);

    //obstacle6
    auto obs6 = Sprite::create("box2.png");
    obs6->setPosition(3200, 350);
    obs6->setScale(2);
    auto spriteBody6 = PhysicsBody::createBox(obs6->getContentSize() / 1, PhysicsMaterial(1.0f, 1.0f, 1.0f));
    spriteBody6->setGravityEnable(false);
    spriteBody6->setDynamic(false);
    spriteBody6->setContactTestBitmask(1);
    spriteBody6->setCollisionBitmask(1);
    spriteBody6->setCategoryBitmask(1);
    obs6->setRotation(0.0f);
    obs6->setPhysicsBody(spriteBody6);
    auto Push6 = Label::createWithTTF("Don't Step ", "fonts/Marker Felt.ttf", 30);
    Push6->setPosition(Vec2(3200, 420));
    Push6->setTextColor(Color4B::RED);
    auto panic7 = Sprite::create("redd.png");
    panic7->setPosition(Vec2(3200, 380));
    panic7->setScale(0.3);



    //obsatcle7
    auto ground3 = Sprite::create("box1.png");
    ground3->setAnchorPoint(Vec2::ZERO);
    ground3->setPosition(3600, 0);
    ground3->setPosition(3600, 0);
    ground3->setScale(2);
    ground3->setName("ground3");

    auto spriteBody7 = PhysicsBody::createBox(ground3->getContentSize() / 1, PhysicsMaterial(1.0f, 1.0f, 1.0f));
    spriteBody7->setGravityEnable(false);
    spriteBody7->setDynamic(false);
    spriteBody7->setContactTestBitmask(1);
    spriteBody7->setCollisionBitmask(1);
    spriteBody7->setCategoryBitmask(1);
    ground3->setRotation(0.0f);
    ground3->setPhysicsBody(spriteBody7);

    auto eventListener = EventListenerKeyboard::create();


    eventListener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* player) {

        Vec2 loc = player->getCurrentTarget()->getPosition();
        auto jump = JumpTo::create(1, Point(loc.x + 70, loc.y), 70, 1);

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

    CCPoint newposition = player->getPosition();
    player->setPosition(newposition);
    CCRect frame = CCRect(0, 0, 4000, 720);
    auto followPlayer = Follow::create(player, frame);
    followPlayer->setTarget(player);
    this->runAction(followPlayer);
    this->addChild(ground1, 2);
    this->addChild(ground2, 2);
    this->addChild(ground3, 2);

    this->addChild(player, 3);
    this->addChild(background, 1);

    this->addChild(Push, 2);
    this->addChild(Push1, 2);
    this->addChild(Push2, 2);
    this->addChild(Push3, 2);
    this->addChild(Push4, 2);
    this->addChild(Push5, 2);
    this->addChild(Push6, 2);
    this->addChild(panic, 2);
    this->addChild(panic2, 2);
    this->addChild(panic3, 2);
    this->addChild(panic4, 2);
    this->addChild(panic5, 2);
    this->addChild(panic6, 2);
    this->addChild(panic7, 2);
    this->addChild(obs2, 2);
    this->addChild(obs3, 2);
    this->addChild(obs4, 2);
    this->addChild(obs5, 2);
    this->addChild(obs6, 2);
  
    
    ui::Button* btn1 = ui::Button::create("p.png");
    btn1->setPosition(Vec2(3900, 420));
    btn1->addTouchEventListener(CC_CALLBACK_1(GameScene2::GoToGameScene3, this));
    this->addChild(btn1, 3);
    return true;
}
void GameScene2::GoToGameScene3(cocos2d::Ref* sender) {
    auto scene2 = GameScene3::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene2));
}
