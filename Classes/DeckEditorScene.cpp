#include "DeckEditorScene.h"
#include "SimpleAudioEngine.h"
#include "Global.h"
#include "Card.h"

USING_NS_CC;

Scene* DeckEditor::createScene()
{
    return DeckEditor::create();
}

// Initialize instance
bool DeckEditor::init()
{
    if (!Scene::init()) {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

  	// Deck editor title field
  	CCLabelTTF* title_label=CCLabelTTF::create("Deck Editor", "Arial.fnt", 20);
  	title_label->setPosition(ccp(200,200));
  	this->addChild(title_label);

  	// Deck name input field
  	std::string deckNameSprite = "test-card.png";
  	_deckName = ui::EditBox::create(editBoxSize, ui::Scale9Sprite::create(deckNameSprite));
  	_deckName->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height*3/4));
  	_deckName->setFontName("Paint Boy");
  	_deckName->setFontSize(25);
  	_deckName->setFontColor(Color3B::RED);
  	_deckName->setPlaceHolder("Name:");
  	_deckName->setPlaceholderFontColor(Color3B::WHITE);
  	_deckName->setMaxLength(8);
  	_deckName->setReturnType(ui::EditBox::KeyboardReturnType::DONE);
  	_deckName->setDelegate(this);
  	this->addChild(_deckName);

  	Vec2 cardPos;
  	Sprite cardSpr;
  	// For each card in the game, create a visualization of it for the deck editor
  	for(Card* card : Global::cards) {
    		std::string spriteSrc;
    		std::map<std::string, Card*>::iterator cIter
    		for(cIter = Global::cards.begin(); cIter != Global::card.end(); cIter++)) {
      			cardSpr = Sprite::create(cIter->second->getSpriteName());
      			// TODO: Card sprite position algorithm
      			cardPos = Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);
      			cardSpr->setPosition(cardPos);
      		  this->addChild(cardSpr); // TODO: This might break? Investigate pointer logic
    		}
  	}

    return true;
}

void DeckEditor::saveDeck(std::string deckName)
{
	// Format the deck into a single string like "Card A|Card B|Card C"
	std::ostringstream oss;
   	std::copy(deck.begin(), deck.end() - 1, std::ostream_iterator<int>(oss, "|"));
   	oss << v.back();
	std::string deckName = oss.str();
	// Now save the deck string
	CCUserDefault* ccud = CCUserDefault::sharedUserDefault();
	ccud->setStringForKey(deckName.c_str(), deckString);
	ccud->flush();
}

void DeckEditor::loadDeck(std::string deckName)
{
	deck.clear();
	// Grab the deck string
	CCUserDefault* ccud=CCUserDefault::sharedUserDefault();
	std::string deckStr = ccud->getStringForKey(deckName.c_str());
	// For each card in the deck string, add it to the deck
	std::stringstream ss(deckStr);
	while(getline(ss, std::string card, '|')) {
		deck.push_back(card);
	}
}

void DeckEditor::menuCloseCallback(Ref* pSender)
{
    // Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
