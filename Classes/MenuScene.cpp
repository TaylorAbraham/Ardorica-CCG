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

    // Initialize and place sample card sprite
    mySprite = Sprite::create("test-card.png");
    mySprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(mySprite);

    // Move sample sprite
    auto action = MoveBy::create(3, Vec2(100, 0));
    mySprite->runAction(action);

    return true;
}

// Creates a local card database from the card database XML file
void MainMenu::loadCardDatabase()
{
    tinyxml2::XMLDocument xml_doc;

    tinyxml2::XMLError eResult = xml_doc.LoadFile("../Data/CardDatabase.xml");
    if(eResult != tinyxml2::XML_SUCCESS) {
        MessageBox("Error loading database or database could not be found.",
                          "Database not loaded!");
        return;
    }

    tinyxml2::XMLNode* root = xml_doc.FirstChildElement("ardorica_card_database");
    if(root == nullptr) {
        MessageBox("Database XML file is invalid or corrupt.",
                          "Unreadable database");
        return;
    }

    tinyxml2::XMLElement* card = root->FirstChildElement("card");
    std::string cardName;
    int cardStr, cardTou, cardClk, iOutInt;
    while(card != nullptr) {
        cardName = card->FirstChildElement("name")->GetText();
        cardName = "test";
        cardStr = card->FirstChildElement("strength")->QueryIntText(&iOutInt);
        cardTou = card->FirstChildElement("toughness")->QueryIntText(&iOutInt);
        cardClk = card->FirstChildElement("clock")->QueryIntText(&iOutInt);
        //Global::cards.insert(std::make_pair(cardName, new Card(cardStr, cardTou, cardClk)));
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
