#include "playeritem.h"

PlayerItem::PlayerItem(direction dir, int cardCount, QPointF centerPoint, QObject* parent)
    : QObject(parent)
{
    this->centerPoint = centerPoint;
    playerDirection = dir;
    layoutKey = QString::number(playerDirection);

    specialCard = getSpecialCard();

    measureLayout(cardCount);
    createCards(cardCount);
}

PlayerItem::PlayerItem(direction dir, std::vector<Card> humanCards, QPointF centerPoint)
{
    this->centerPoint = centerPoint;
    this->playerDirection = dir;
    this->layoutKey = QString::number(playerDirection);
    this->measureLayout(humanCards.size());
    this->createHumanCards(humanCards);
}

PlayerItem::direction PlayerItem::getDirection()
{
    return playerDirection;
}

void PlayerItem::createCards(int cardCount)
{
    for (int i = 0; i < cardCount; i++) {
        CardItem* card = new CardItem(specialCard);

        card->setPos(layout.value(layoutKey + "X"), layout.value(layoutKey + "Y"));

        if (playerDirection == direction::LEFT || playerDirection == direction::RIGHT) {
            layout.insert(layoutKey + "Y", layout.value(layoutKey + "Y") + cardGap);
        } else {
            layout.insert(layoutKey + "X", layout.value(layoutKey + "X") + cardGap);
        }

        cards->append(card);
    }
}

/**
 * Sry, but we need a own method for the human player, otherwise i go insane
 * @brief PlayerItem::createHumanCards
 * @param humanCards
 */
void PlayerItem::createHumanCards(std::vector<Card> humanCards)
{
    for (unsigned int i = 0; i < humanCards.size(); i++) {
        CardItem* card = new CardItem(humanCards.at(i));
        card->setPos(layout.value(layoutKey + "X"), layout.value(layoutKey + "Y"));
        layout.insert(layoutKey + "X", layout.value(layoutKey + "X") + cardGap);

        cards->append(card);
    }
}

/**
 * Yes, this is measureLayout(), it calculates all the x and y points for every 3 player. I know it seems a little bit fucked up, and maybe we should
 * change it. But at this point I dont know how to make it better.
 * @brief PlayerItem::measureLayout
 * @param cardCount
 */
void PlayerItem::measureLayout(int cardCount)
{

    if (playerDirection == direction::LEFT) {
        int playerCardsWidth = (cardCount - 1 * cardGap) + (cardWidth - cardGap) - cardWidth;
        layout.insert(QString::number(direction::LEFT) + "X", cardWidth - 30);
        layout.insert(QString::number(direction::LEFT) + "Y", ((centerPoint.y() / 2) - (playerCardsWidth / 2)));
    }
    if (playerDirection == direction::TOP) {
        int playerCardsWidth = (cardCount * cardGap);
        layout.insert(QString::number(direction::TOP) + "X", ((centerPoint.x()) - (playerCardsWidth / 2) - cardGap));
        layout.insert(QString::number(direction::TOP) + "Y", cardHeight - 70);
    }
    if (playerDirection == direction::HUMAN) {
        int playerCardsWidth = cardCount * cardGap;
        layout.insert(QString::number(direction::HUMAN) + "X", ((centerPoint.x()) - (playerCardsWidth / 2) - cardGap));
        layout.insert(QString::number(direction::HUMAN) + "Y", centerPoint.y() * 2 - cardHeight - 30);
    }
    if (playerDirection == direction::RIGHT) {
        int playerCardsWidth = (cardCount - 1 * cardGap) + (cardWidth - cardGap) - cardWidth;
        layout.insert(QString::number(direction::RIGHT) + "X", centerPoint.x() * 2 - cardWidth - 30);
        layout.insert(QString::number(direction::RIGHT) + "Y", ((centerPoint.y() / 2) - (playerCardsWidth / 2)));
    }
}

void PlayerItem::setPlayableCards(std::vector<Card> playableCards)
{
    for (unsigned int i = 0; i < playableCards.size(); ++i) {
        for (int j = 0; j < cards->size(); ++j) {
            if (playableCards.at(i) == cards->at(j)->getCard()) {
                CardItem* cardItem = cards->at(j);
                cardItem->setPos(cardItem->getX(), cardItem->getY() - offsetPlayableCard);
                cardItem->getGraphicsItem()->setFlag(QGraphicsItem::ItemIsSelectable, true);

                /*QGraphicsColorizeEffect *effect = new QGraphicsColorizeEffect();
                effect->setColor(QColor(0,0,0,0));
                effect->setStrength(1);
                cards->at(j)->getGraphicsItem()->setGraphicsEffect(effect);
                */
            }
        }
    }
}

void PlayerItem::unsetPlayableCards()
{
    for (int i = 0; i < cards->size(); ++i) {
        if (cards->at(i)->getGraphicsItem()->flags() == QGraphicsItem::ItemIsSelectable) {
            CardItem* cardItem = cards->at(i);
            cardItem->setPos(cards->at(i)->getX(), cards->at(i)->getY() + offsetPlayableCard);
            cardItem->getGraphicsItem()->setFlag(QGraphicsItem::ItemIsSelectable, false);
        }
    }
}

void PlayerItem::addCard(Card& card)
{
    CardItem* cardItem = NULL;
    if (this->playerDirection == PlayerItem::direction::HUMAN) {
        cardItem = new CardItem(card);
    } else {
        cardItem = new CardItem(getSpecialCard());
    }
    cards->append(cardItem);
}

void PlayerItem::removeCard(Card& card)
{
}

CardItem* PlayerItem::findCard(Card& card)
{
    for (int i = 0; i < cards->size(); ++i) {
        if (card == cards->at(i)->getCard()) {
            return cards->at(i);
        }
    }
    //TODO Maybe throw Exception?!?!
    return NULL;
}

CardItem::specialCards PlayerItem::getSpecialCard()
{
    switch (playerDirection) {
    case PlayerItem::direction::LEFT:
        return CardItem::specialCards::BLUE_HORIZONTAL;
        break;
    case PlayerItem::direction::RIGHT:
        return CardItem::specialCards::BLUE_HORIZONTAL;
        break;
    case PlayerItem::direction::TOP:
        return CardItem::specialCards::BLUE_VERTICAL;
        break;
    default:
        return CardItem::specialCards::BLUE_HORIZONTAL;
        break;
    }
}

QVector<CardItem*>* PlayerItem::getCards()
{
    return cards;
}
