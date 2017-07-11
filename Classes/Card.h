#ifndef __CARD_H__
#define __CARD_H__

#include "cocos2d.h"

class Card : public cocos2d::CCNode
{
public:
    Card(int s, int t, int c);
    Card(int s, int t, int c, std::string e);

    void attack();
    void glory();
    void enter();
    void death();

    int getStrength();
    void setStrength(int newStrength);
    void modifyStrength(int amount);
    int getToughness();
    void setToughness(int newToughness);
    void modifyToughness(int amount);
    int getClock();
    void setClock(int newClock);
    void decClock();
    std::string getEffect();
    void setEffect(std::string newEffect);
    int getHealth();
    bool setHealth(int newHealth);
    bool loseHealth(int damage);

private:
    int strength;
    int toughness;
    int clockVal;
    std::string effect;
    int health;
    void doEffect(std::string e);
};

#endif // __CARD_H__
