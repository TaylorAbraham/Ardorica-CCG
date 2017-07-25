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

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    loadCardDatabase();

    return true;
}

// Creates a local card database from the card database XML file
void MainMenu::loadCardDatabase()
{
    std::map<std::string, std::unique_ptr<Card>> cardz; // Testing variable, to be replaced by global card map
    //std::string data = FileUtils::getInstance()->getStringFromFile("data.xml");
    auto fileUtils = FileUtils::getInstance();
    std::string path = fileUtils->fullPathForFilename(std::string("data.xml"));
    //reads contents of the file into a string
    auto xmlData = fileUtils->getStringFromFile(path);
    MessageBox(path.c_str(), "path.c_str()");
    tinyxml2::XMLDocument xmlDoc;
    MessageBox(xmlData.c_str(), "xmlData.c_str()");
    tinyxml2::XMLError eResult = xmlDoc.Parse(xmlData.c_str());
    if(eResult != tinyxml2::XML_SUCCESS) {
        std::ostringstream oss;
        oss << eResult;
        std::string error = "Error loading database. Error code: " + oss.str();
        MessageBox(error.c_str(), "Database not loaded!");
        return;
    }

    tinyxml2::XMLNode* root = xmlDoc.RootElement();
    if(root == nullptr) {
        std::ostringstream oss;
        oss << eResult;
        std::string error = "Database XML file is invalid or corrupt. Error code: " + oss.str();
        MessageBox(error.c_str(), "Bad database!");
        return;
    }

    std::string cardName, cardSpriteName, cardEffect;
    int cardStr, cardTou, cardClk, iOutInt;
    for(tinyxml2::XMLElement* card = root->FirstChildElement("card");
            card != nullptr; card = card->NextSiblingElement("card")) {
        cardName = card->FirstChildElement("name")->GetText();
        cardStr = card->FirstChildElement("strength")->QueryIntText(&iOutInt);
        //cardTou = card->FirstChildElement("toughness")->QueryIntText(&iOutInt);
        //cardClk = card->FirstChildElement("clock")->QueryIntText(&iOutInt);
        //cardEffect = card->FirstChildElement("effect")->GetText();
        //cardSpriteName = card->FirstChildElement("image")->GetText();
        //cardz.insert(std::make_pair(cardName, std::unique_ptr<Card>(new Card(cardStr, cardTou, cardClk, cardEffect, cardSpriteName))));
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
