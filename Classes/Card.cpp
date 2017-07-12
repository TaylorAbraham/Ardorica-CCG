#include "Card.h"
#include <regex>

// Constructors
Card::Card(int s, int t, int c)
{
    setStrength(s);
    setToughness(t);
    setClock(c);
}

Card::Card(int s, int t, int c, std::str e)
{
    Card(s, t, c);
    setEffect(e);
}


/* Actions and abilities */
void attack(Card* enemy)
{
    // Check if effect includes an 'on attack' effect
    if(effect.find("attack()") != std::string::npos) {
        // It does, so run the effect text after the 'attack()->' trigger text
        doEffect(effect.substr(effect.find("->") + 1));
    }
    // Attack logic
    if(enemy == nullptr) {
        // No enemy, so attack opponent directly
    } else {
        // Attack enemy fighter
        enemy.setHealth
    }
}

// Run a card effect
void Card::doEffect(e) {
    // Regex that checks for statChange(X,Y)
    // EX: statChange(2,-1)
    std::regex statChangeReg("statChange\(([+-]?\d+),([+-]?\d+)\)");
    std::smatch regMatch;

    if(std::regex_match(e, regMatch, statChangeReg)) {
        // statChange(X,Y) - Adjust strength and toughness values (relative)
        modifyStrength(std::stoi(regMatch[0].str()));
        modifyToughness(std::stoi(regMatch[1].str()));
    } else {
        MessageBox("The card database was not set up correctly.",
                          "Invalid card effect!");
    }
}


/* Getters, setters, and modifiers */
int Card::getStrength()
{
    return strength;
}

void Card::setStrength(int newStrength)
{
    if(newStrength >= 0) {
        strength = newStrength;
    } else {
        strength = 0;
    }
}

void Card::modifyStrength(int amount) {
    setStrength(getStrength() - amount);
}

int Card::getToughness()
{
    return toughness;
}

void Card::setToughness(int newToughness)
{
    if(newToughness >= 0) {
        toughness = newToughness;
    } else {
        toughness = 0;
    }
}

void Card::modifyToughness(int amount) {
    setToughness(getToughness() - amount);
}

int Card::getClock()
{
    return clockVal;
}

void Card::setClock(int newClock)
{
    clockVal = newClock;
    if(clockVal <= 0) {
        enter();
    }
}

std::string Card::getEffect()
{
    return effect;
}

void Card::setEffect(std::string newEffect)
{
    effect = newEffect;
}

void Card::decClock()
{
    setClock(getClock() - 1);
}

int Card::getHealth()
{
    return health;
}

// Returns true if this causes death
bool Card::setHealth(int newHealth)
{
    health = newHealth;
    if(health <= 0)
        death();
        return true;
    }
    return false;
}

// Returns true if this causes death
bool Card::loseHealth(int amount) {
    return setHealth(getHealth() - amount);
}
