#include "MenuScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* Menu::createScene()
{
    return Menu::create();
}

// Initialize instance
bool Menu::init()
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


void Menu::menuCloseCallback(Ref* pSender)
{
    // Free objects referenced by vectors of pointers
    std::for_each(cards.begin(), cards.end(), delete_pointed_to<base>);

    // Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
