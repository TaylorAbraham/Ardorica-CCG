#include "MenuScene.h"
#include "SimpleAudioEngine.h"
#include "Global.h"
#include "tinyxml2/tinyxml2.h"

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
    std::map<std::string, std::unique_ptr<Card>> cards;
    tinyxml2::XMLDocument xml_doc;

    tinyxml2::XMLError eResult = xml_doc.LoadFile("../Data/CardDatabase.xml");
    if(eResult != tinyxml2::XML_SUCCESS) {
        std::string error = "Error loading database. Error code: " + std::to_string(eResult);
        MessageBox(error, "Database not loaded!");
        return;
    }

    tinyxml2::XMLNode* root = xml_doc.FirstChildElement("ardorica_card_database");
    if(root == nullptr) {
        std::string error = "Database XML file is invalid or corrupt. Error code: " + std::to_string(eResult);
        MessageBox(error, "Unreadable database");
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
        Global::cards.insert(std::make_pair(cardName, new Card(cardStr, cardTou, cardClk, cardEffect, cardSpriteName)));
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
