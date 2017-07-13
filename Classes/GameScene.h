#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Card.h"

class Game : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // A selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // Implement the "static create()" method manually
    CREATE_FUNC(Game);

    cocos2d::Sprite *mySprite;
};

#endif // __GAME_SCENE_H__
