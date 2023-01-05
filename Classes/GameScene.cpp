#include "GameScene.h"
#include "cocos2d.h"
using namespace cocos2d::ui;
#include <png/include/win32/png.h>
#include "GameScene - 2.h"
#include "Definitions.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
USING_NS_CC_EXT;
USING_NS_CC;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    //auto scene = Scene::create();
    auto scene = Scene::createWithPhysics();
    PhysicsWorld* world = scene->getPhysicsWorld();
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
    layer->setPhysicsWorld(scene->getPhysicsWorld());
    // add layer as a child to scene
    scene->addChild(layer);



    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto background = Sprite::create("background.jpg");
    background->setAnchorPoint(Vec2::ZERO);
    background->setPosition(0, 0);
    background->setContentSize(CCSize(5000, 2000));
    auto ground1 = Sprite::create("box1.png");
    ground1->setAnchorPoint(Vec2::ZERO);
    ground1->setPosition(0, 0);


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
    auto obs1 = Sprite::create("box2.png");
    obs1->setPosition(1050, 280);
    obs1->setScale(2);
    auto spriteBody1 = PhysicsBody::createBox(obs1->getContentSize() / 1, PhysicsMaterial(1.0f, 1.0f, 1.0f));
    spriteBody1->setGravityEnable(false);
    spriteBody1->setDynamic(false);
    spriteBody1->setContactTestBitmask(1);
    spriteBody1->setCollisionBitmask(1);
    spriteBody1->setCategoryBitmask(1);
    obs1->setRotation(0.0f);
    obs1->setPhysicsBody(spriteBody1);
    //obstacle 2
    auto obs2 = Sprite::create("box2.png");
    obs2->setPosition(1550, 300);
    obs2->setScale(2);
    auto spriteBody2 = PhysicsBody::createBox(obs2->getContentSize() / 1, PhysicsMaterial(1.0f, 1.0f, 1.0f));
    spriteBody2->setGravityEnable(false);
    spriteBody2->setDynamic(false);
    spriteBody2->setContactTestBitmask(1);
    spriteBody2->setCollisionBitmask(1);
    spriteBody2->setCategoryBitmask(1);
    obs2->setRotation(0.0f);
    obs2->setPhysicsBody(spriteBody2);
    //obstacle 3
    auto obs3 = Sprite::create("box2.png");
    obs3->setPosition(1700, 300);
    obs3->setScale(2);
    auto spriteBody3 = PhysicsBody::createBox(obs3->getContentSize() / 1, PhysicsMaterial(1.0f, 1.0f, 1.0f));
    spriteBody3->setGravityEnable(false);
    spriteBody3->setDynamic(false);
    spriteBody3->setContactTestBitmask(1);
    spriteBody3->setCollisionBitmask(1);
    spriteBody3->setCategoryBitmask(1);
    obs3->setRotation(0.0f);
    obs3->setPhysicsBody(spriteBody3);
    //obstacle 4
    auto obs4 = Sprite::create("box2.png");
    obs4->setPosition(1800, 300);
    obs4->setScale(2);
    auto spriteBody4 = PhysicsBody::createBox(obs4->getContentSize() / 1, PhysicsMaterial(1.0f, 1.0f, 1.0f));
    spriteBody4->setGravityEnable(false);
    spriteBody4->setDynamic(false);
    spriteBody4->setContactTestBitmask(1);
    spriteBody4->setCollisionBitmask(1);
    spriteBody4->setCategoryBitmask(1);
    obs4->setRotation(0.0f);
    obs4->setPhysicsBody(spriteBody4);
    //obstacle 5
    auto obs5 = Sprite::create("box1.png");
    obs5->setPosition(2500, 0);
    obs5->setScale(2);
    auto spriteBody5 = PhysicsBody::createBox(obs5->getContentSize() / 1, PhysicsMaterial(1.0f, 1.0f, 1.0f));
    spriteBody5->setGravityEnable(false);
    spriteBody5->setDynamic(false);
    spriteBody5->setContactTestBitmask(1);
    spriteBody5->setCollisionBitmask(1);
    spriteBody5->setCategoryBitmask(1);
    obs5->setRotation(0.0f);
    obs5->setPhysicsBody(spriteBody5);
    //obstacle 6
    auto obs6 = Sprite::create("box4.png");
    obs6->setPosition(3150, 100);
    obs6->setScale(1.5);
    auto spriteBody6 = PhysicsBody::createBox(obs6->getContentSize() / 1, PhysicsMaterial(1.0f, 1.0f, 1.0f));
    spriteBody6->setGravityEnable(false);
    spriteBody6->setDynamic(false);
    spriteBody6->setContactTestBitmask(1);
    spriteBody6->setCollisionBitmask(1);
    spriteBody6->setCategoryBitmask(1);
    obs6->setRotation(0.0f);
    obs6->setPhysicsBody(spriteBody6);
    //obstacle 8
    auto ground2 = Sprite::create("box1.png");
    ground2->setPosition(3800, 0);
    ground2->setScale(2);
    auto spriteBody8 = PhysicsBody::createBox(ground2->getContentSize() / 1, PhysicsMaterial(1.0f, 1.0f, 1.0f));
    spriteBody8->setGravityEnable(false);
    spriteBody8->setDynamic(false);
    spriteBody8->setContactTestBitmask(1);
    spriteBody8->setCollisionBitmask(1);
    spriteBody8->setCategoryBitmask(1);
    ground2->setRotation(0.0f);
    ground2->setPhysicsBody(spriteBody8);










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
    this->addChild(obs1, 2);
    this->addChild(obs2, 2);
    this->addChild(obs3, 2);
    this->addChild(obs4, 2);
    this->addChild(obs5, 2);
    this->addChild(obs6, 2);
    this->addChild(ground2, 2);
    this->addChild(player, 2);
    this->addChild(background, 1);


    ui::Button* btn1 = ui::Button::create("p.png");
    btn1->setPosition(Vec2(3900,420));
    btn1->addTouchEventListener(CC_CALLBACK_1(GameScene::GoToGameScene2, this));
    this->addChild(btn1, 3);

    return true;
}

void GameScene::GoToGameScene2(cocos2d::Ref* sender) {
    auto scene2 = GameScene2::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene2));

}



