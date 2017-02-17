#include "SplashScene.h"
#include "SplashScene2.h"
#include "MainMenuScene.h"
#include "Definitions.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;
USING_NS_CC;

Scene* SplashScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = SplashScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SplashScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    CocosDenshion::SimpleAudioEngine::getInstance( )->preloadEffect( "Sounds/Hit.mp3" );
    CocosDenshion::SimpleAudioEngine::getInstance( )->preloadEffect( "Sounds/Point.mp3" );
    CocosDenshion::SimpleAudioEngine::getInstance( )->preloadEffect( "Sounds/Wing.mp3" );
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    this->scheduleOnce( schedule_selector( SplashScene::GoToSplashScene2 ), DISPLAY_TIME_SPLASH_SCENE );

    auto backgroundSprite = Sprite::create( "Android/SplashScene1.png" );
    backgroundSprite->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y) );
    
    this->addChild( backgroundSprite );
    
    return true;
}

void SplashScene::GoToSplashScene2( float dt )
{
	auto scene = SplashScene2::createScene();
    
	Director::getInstance()->replaceScene(TransitionSlideInT::create(TRANSITION_TIME, scene));
}



