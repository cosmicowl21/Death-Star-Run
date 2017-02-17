#include "Player.h"
#include "Definitions.h"

USING_NS_CC;

Player::Player( cocos2d::Layer *layer )
{
    visibleSize = Director::getInstance( )->getVisibleSize( );
    origin = Director::getInstance( )->getVisibleOrigin( );
    
    flappyBird = Sprite::create( "Ball.png" );
    flappyBird->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y ) );
    
    auto flappyBody = PhysicsBody::createCircle( flappyBird->getContentSize( ).width / 2 );
    flappyBody->setCollisionBitmask( BIRD_COLLISION_BITMASK );
    flappyBody->setContactTestBitmask( true );
    
    flappyBird->setPhysicsBody( flappyBody );
    
    layer->addChild( flappyBird, 100 );
    
    isFalling = true;
}

void Player::Fall( )
{
    if ( true == isFalling )
    {
        flappyBird->setPositionX( visibleSize.width / 2 + origin.x );
        flappyBird->setPositionY( flappyBird->getPositionY() - ( BIRD_FALLING_SPEED * visibleSize.height ) );
    }
    else
    {
        flappyBird->setPositionX( visibleSize.width / 2 + origin.x );
        flappyBird->setPositionY( flappyBird->getPositionY() + ( BIRD_FALLING_SPEED * visibleSize.height ) );
    }
}




