#ifndef __DECK_EDITOR_SCENE_H__
#define __DECK_EDITOR_SCENE_H__

#include "cocos2d.h"

class DeckEditor : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // A selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // Implement the "static create()" method manually
    CREATE_FUNC(DeckEditor);

    cocos2d::Sprite *mySprite;
private:
    void saveDeck(std::string deckName);
    void loadDeck(std::string deckName);

    std::vector<std::string> deck;
};

#endif // __DECK_EDITOR_SCENE_H__
