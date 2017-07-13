#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"
#include "Card.h"

class Player
{
public:
    Player(int l);

    unique_ptr<Card> drawCard();
    void shuffleDeck();

    int getLife();
    bool setLife(int newLife);
    bool loseLife(int damage);
    std::vector<unique_ptr<Card>>& getHand();
    std::vector<unique_ptr<Card>>& getField();

private:
    int life;
    std::vector<unique_ptr<Card>> deck;
    std::vector<unique_ptr<Card>> hand;
    std::vector<unique_ptr<Card>> field;
};

#endif // __PLAYER_H__
