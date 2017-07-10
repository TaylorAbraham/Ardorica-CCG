#include "Card.h"

Card::Card(int startStrength, int startToughness) {
    strength = startStrength;
    toughness = startToughness;
}

/* Getters and setters */
int Card::getStrength()
{
    return strength;
}

void Card::setStrength(newStrength)
{
    if(newStrength >= 0) {
        strength = newStrength;
    } else {
        strength = 0;
    }
}

int Card::getToughness()
{
    return toughness;
}

void Card::setToughness(newToughness)
{
    if(newToughness >= 0) {
        toughness = newToughness;
    } else {
        toughness = 0;
    }
}

int Card::getHealth()
{
    return health;
}

// Returns true if this causes death
bool Card::setHealth(newHealth)
{
    health = newHealth;
    if(health <= 0)
        death();
        return true;
    }
    return false;
}

int Card::getClock()
{
    return clockVal;
}

void Card::setClock(newClock)
{
    clockVal = newClock;
    if(clockVal <= 0) {
        enter();
    }
}

void Card::decClock()
{
    setClock(getClock() - 1);
}
