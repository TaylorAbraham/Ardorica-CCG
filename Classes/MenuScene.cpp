#include "MenuScene.h"
#include "SimpleAudioEngine.h"
#include "Global.h"
#include "Card.cpp"
#include "tinyxml2/tinyxml2.h"
#include <sstream>

USING_NS_CC;

Scene* MainMenu::createScene()
{
    return MainMenu::create();
}

// Initialize instance
bool MainMenu::init()
{
    if (!Scene::init()) {
        return false;
    }

    loadCardDatabase();

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    return true;
}

// Creates a local card database from the card database XML file
void MainMenu::loadCardDatabase()
{
    //std::map<std::string, std::unique_ptr<Card>> cards;
    std::map<std::string, std::unique_ptr<Card>> cardz;
    tinyxml2::XMLDocument xmlDoc;
    tinyxml2::XMLError eResult = xmlDoc.LoadFile("CardDatabase.xml");
    if(eResult != tinyxml2::XML_SUCCESS) {
        std::ostringstream oss;
        oss << eResult;
        std::string error = "Error loading database. Error code: " + oss.str();
        MessageBox(error.c_str(), "Database not loaded!");
        //MessageBox(eResult, "Database not loaded!");
        return;
    }

    tinyxml2::XMLNode* root = xmlDoc.FirstChildElement("ardorica_card_database");
    if(root == nullptr) {
        //std::string error = "Database XML file is invalid or corrupt. Error code: " + std::to_string(eResult);
        //MessageBox(xmlDoc.GetErrorStr1(), "Invalid database!");
        //MessageBox(xmlDoc.GetErrorStr2(), "Invalid database!");
        return;
    }

    tinyxml2::XMLElement* card = root->FirstChildElement("card");
    std::string cardName, cardSpriteName, cardEffect;
    int cardStr, cardTou, cardClk, iOutInt;
    while(card != nullptr) {
        cardName = card->FirstChildElement("name")->GetText();
        cardStr = card->FirstChildElement("strength")->QueryIntText(&iOutInt);
        cardTou = card->FirstChildElement("toughness")->QueryIntText(&iOutInt);
        cardClk = card->FirstChildElement("clock")->QueryIntText(&iOutInt);
        cardEffect = card->FirstChildElement("effect")->GetText();
        cardSpriteName = card->FirstChildElement("image")->GetText();
        cardz.insert(std::make_pair(cardName, std::unique_ptr<Card>(new Card(cardStr, cardTou, cardClk, cardEffect, cardSpriteName))));
    }
}

void MainMenu::menuCloseCallback(Ref* pSender)
{
    // Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
