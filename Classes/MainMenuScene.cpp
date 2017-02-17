#include "MainMenuScene.h"
#include "GameScene.h"
#include "Definitions.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
using namespace CocosDenshion;

#define MainTheme "Sounds/MainTheme.mp3"
#define Play "Sounds/play.mp3"

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

	SimpleAudioEngine::getInstance()->playBackgroundMusic(MainTheme);
    auto backgroundSprite = Sprite::create( "Android/Starwars.png" );
    backgroundSprite->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y ) );
    this->addChild( backgroundSprite );
    
    auto playItem = MenuItemImage::create( "Android/PlayGame.png", "Android/Pressed.png", CC_CALLBACK_1( MainMenuScene::GoToGameScene, this ) );
    playItem->setPosition( Point( visibleSize.width / 4.5 + origin.x, visibleSize.height / 5 + origin.y ) );


    auto menu = Menu::create( playItem, NULL );
    menu->setPosition( Point::ZERO );
    this->addChild( menu );

	auto QuitItem = MenuItemImage::create("Android/QuitGame.png", "Android/Pressed.png", CC_CALLBACK_1(MainMenuScene::menuCloseCallback, this));
	QuitItem->setPosition(Point(visibleSize.width / 1.4 + origin.x, visibleSize.height / 5 + origin.y));
	
	auto Quit = Menu::create(QuitItem, NULL);
	Quit->setPosition(Point::ZERO);
	this->addChild(Quit);
    
    return true;
}

void MainMenuScene::GoToGameScene( cocos2d::Ref *sender )
{
    auto scene = GameScene::createScene();
    
	Director::getInstance()->replaceScene(TransitionSlideInT::create(TRANSITION_TIME, scene));
	SimpleAudioEngine::getInstance()->playEffect(Play);
	//SimpleAudioEngine::getInstance()->stopBackgroundMusic(MainTheme);
}


void MainMenuScene::menuCloseCallback(cocos2d::Ref *pSender)
{
	Director::getInstance()->end();
}