#include "GameScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

#define PTM_RATIO 32 // Pixel to metre ratio

// Test values. These will be set up by the deck loading mechanic added later
deckSize1 = 5;
deckSize2 = 5;
life1 = 30;
life2 = 30;

Scene* Game::createScene()
{
    return Game::create();
}

// Initialize instance
bool Game::init()
{
    if (!Scene::init()) {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // Initialize and place sample card sprite
    mySprite = Sprite::create("test-card.png");
    mySprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(mySprite);

    // Move sample sprite
    auto action = MoveBy::create(3, Vec2(100, 0));
    mySprite->runAction(action);

    return true;
}


void Game::menuCloseCallback(Ref* pSender)
{
    // Free objects referenced by vectors of pointers
    // TODO: Look into unique pointers
    std::for_each(deck1.begin(), deck1.end(), delete_pointed_to<base>);
    std::for_each(deck2.begin(), deck2.end(), delete_pointed_to<base>);
    std::for_each(hand1.begin(), hand1.end(), delete_pointed_to<base>);
    std::for_each(hand2.begin(), hand2.end(), delete_pointed_to<base>);
    std::for_each(field1.begin(), field1.end(), delete_pointed_to<base>);
    std::for_each(field2.begin(), field2.end(), delete_pointed_to<base>);
    // Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
