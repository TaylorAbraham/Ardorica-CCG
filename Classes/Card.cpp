#include "Card.h"
#include <regex>

// Constructor
Card::Card(int s, int t, int c, std::string e, std::string sn)
{
    setStrength(s);
    setToughness(t);
    setClock(c);
    setEffect(e);
    setSpriteName(sn);
}


/* Actions and abilities */

// On fighter attack
void Card::attack(Card* enemy)
{
    // Check if effect includes an 'on attack' effect
    if(effect.find("attack()") != std::string::npos) {
        // It does, so run the effect text after the 'attack()->' trigger text
        doEffect(effect.substr(effect.find("->") + 1));
    }
    // Attack logic
    if(enemy == nullptr) {
        // No enemy, so attack opponent directly
        // TODO
    } else {
        // Attack enemy fighter
        int dmgModifier = 0;
        std::regex shieldReg("shield(([+-]?[0-9]+))");
        std::smatch regMatch;
        if(std::regex_match(enemy->getEffect(), regMatch, shieldReg)) {
            // Enemy has a 'shield' effect, so reduce damage dealt
            dmgModifier = -1 * std::atoi(regMatch[0].str().c_str());
        }
        // All damage modifiers have been calculated. Now deal the damage.
        if(enemy->loseHealth(getStrength() + dmgModifier)) {
            // Enemy died from this attack, so glory ability triggers
            glory();
        }
    }
}

// When a fighter kills an enemy
void Card::glory() {
    // Check if effect includes a 'glory' effect
    if(effect.find("glory()") != std::string::npos) {
        // It does, so run the effect text after the 'glory()->' trigger text
        doEffect(effect.substr(effect.find("->") + 1));
    }
}

// When this fighter comes into play
void Card::enter() {

}

// When this fighter dies
void Card::death() {
    // Check if effect includes a 'death' effect
    if(effect.find("death()") != std::string::npos) {
        // It does, so run the effect text after the 'death()->' trigger text
        doEffect(effect.substr(effect.find("->") + 1));
    }
}

// Run a card effect
void Card::doEffect(std::string e) {
    // Regex that checks for statChange(X,Y)
    // EX: statChange(2,-1)
    std::regex statChangeReg("statChange(([+-]?[0-9]+),([+-]?[0-9]+))");
    std::smatch regMatch;

    if(std::regex_match(e, regMatch, statChangeReg)) {
        // statChange(X,Y) - Adjust strength and toughness values (relative)
        modifyStrength(std::atoi(regMatch[0].str().c_str()));
        modifyToughness(std::atoi(regMatch[1].str().c_str()));
    } else {
        // No effect detected, but an effect was expected. Database error.
        cocos2d::MessageBox("The card database was not set up correctly.", "Invalid card effect!");
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

void Card::decClock()
{
  setClock(getClock() - 1);
}

std::string Card::getEffect()
{
    return effect;
}

void Card::setEffect(std::string newEffect)
{
    effect = newEffect;
}

std::string Card::getSpriteName()
{
    return spriteName;
}

void Card::setSpriteName(std::string newSpriteName)
{
    spriteName = newSpriteName;
}

int Card::getHealth()
{
    return health;
}

// Returns true if this causes death
bool Card::setHealth(int newHealth)
{
    health = newHealth;
    if(health <= 0) {
        death();
        return true;
    }
    return false;
}

// Returns true if this causes death
bool Card::loseHealth(int amount) {
    return setHealth(getHealth() - amount);
}
