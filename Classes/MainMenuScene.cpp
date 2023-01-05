#include "MainMenuScene.h"
#include "GameScene.h"
#include "Definitions.h"
#include "KeyboardScene.h"
#include "audio/include/SimpleAudioEngine.h"
USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto backgroundSprite = Sprite::create("cool-background (1).png");
    backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    this->addChild(backgroundSprite);

    auto titleSprite = Sprite::create("LOGO.png");
    titleSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height - titleSprite->getContentSize().height));

    this->addChild(titleSprite);

    auto playItem = MenuItemImage::create("p.png", "c.png", CC_CALLBACK_1(MainMenuScene::GoToGameScene, this));
    playItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    auto menu = Menu::create(playItem, NULL);
    menu->setPosition(Point::ZERO);

    this->addChild(menu);
    auto audioEngine = CocosDenshion::SimpleAudioEngine::getInstance();
    audioEngine->preloadBackgroundMusic("Farruko - On My Way.mp3");
    audioEngine->playBackgroundMusic("Farruko - On My Way.mp3", true);
    audioEngine->setBackgroundMusicVolume(0.5f); // Réglez le volume à 50%
    float volume = audioEngine->getBackgroundMusicVolume(); // Récupérez le volume actuel
    
  
    return true;
}

void MainMenuScene::GoToGameScene(cocos2d::Ref* sender)
{
    auto stage = GameScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, stage));
}