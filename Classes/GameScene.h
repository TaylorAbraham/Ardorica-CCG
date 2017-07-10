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
    int deckSize1;
    int deckSize2;
    int life1;
    int life2;
    std::vector<Card*> deck1;
    std::vector<Card*> deck2;
    std::vector<Card*> field1;
    std::vector<Card*> field2;
};

#endif // __GAME_SCENE_H__
