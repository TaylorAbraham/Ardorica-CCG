#ifndef __CARD_H__
#define __CARD_H__

#include "cocos2d.h"

class Card : public cocos2d::CCNode
{
public:
    int getStrength();
    void setStrength();
    int getToughness();
    void setToughness();
    int getHealth();
    bool setHealth();
    int getClock();
    void setClock();
    void decClock();

    void attack();
    void glory();
    void enter();
    void death();

private:
    int strength;
    int toughness;
    int health;
    int clockVal;
};

#endif // __CARD_H__
