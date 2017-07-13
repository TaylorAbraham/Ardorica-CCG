#include "Player.h"
//#include <algorithm> // For random_shuffle

// Constructor
Player::Player(int l)
{
    setLife(l);
}


unique_ptr<Card> Player::drawCard()
{
    std::unique_ptr drawnCard = std::move(deck.back());
    deck.pop_back();
    return drawnCard;
}

void Player::shuffleDeck()
{
    std::random_shuffle(deck.begin(), deck.end());
}


/* Getters, setters, and modifiers */

int Player::getLife()
{
    return life;
}

// Returns true if this causes death
bool Player::setLife(int newLife)
{
    life = newLife;
    if(life <= 0)
        death();
        return true;
    }
    return false;
}

// Returns true if this causes death
bool Player::loseLife(int amount) {
    return setLife(getLife() - amount);
}

std::vector<unique_ptr<Card>>& getHand()
{
    return hand;
}

std::vector<unique_ptr<Card>>& getField()
{
    return field;
}
