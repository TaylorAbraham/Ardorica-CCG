#ifndef __CARD_H__
#define __CARD_H__

class Card
{
public:
    Card(int s, int t, int c, std::string e, std::string sn);

    void attack(Card* enemy);
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
    std::string getSpriteName();
    void setSpriteName(std::string newSpriteName);
    int getHealth();
    bool setHealth(int newHealth);
    bool loseHealth(int damage);

private:
    int strength;
    int toughness;
    int clockVal;
    std::string effect;
    std::string spriteName;
    int health;
    void doEffect(std::string e);
};

#endif // __CARD_H__
