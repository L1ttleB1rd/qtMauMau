#ifndef PLAYERITEM_H
#define PLAYERITEM_H

#include <gui/carditem.h>
#include <vector>
#include <QDebug>
#include <QString>
#include <QGraphicsColorizeEffect>
#include <QColor>
#include <QPainter>

class PlayerItem : public QObject {
    Q_OBJECT
public:
    enum direction {
        LEFT = 1,
        TOP = 2,
        RIGHT = 3,
        HUMAN = 4
    };

    PlayerItem(direction dir, int cardCount, QPointF centerPoint, QObject* parent = 0);
    PlayerItem(direction dir, std::vector<Card> humanCards, QPointF centerPoint);
    void createCards(int cardCount);
    void setPlayableCards(std::vector<Card> playableCards);
    void unsetPlayableCards();
    direction getDirection();
    QVector<CardItem*>* getCards();
    void removeCard(Card &card);
    void addCard(Card &card);

private:
    CardItem* findCard(Card &card);
    void measureLayout(int cardCount);
    CardItem::specialCards getSpecialCard();
    void createHumanCards(std::vector<Card> humanCards);
    QVector<CardItem*>* cards = new QVector<CardItem*>();
    CardItem::specialCards specialCard;
    PlayerItem::direction playerDirection;
    QString layoutKey;
    QHash<QString, int> layout;
    QPointF centerPoint;

    //TODO: set in config.ini not in the code
    int cardWidth = 71;
    int cardHeight = 96;
    int cardGap = 20;
    int offsetPlayableCard = 20;

signals:

public
slots:
};

#endif // PLAYERITEM_H
