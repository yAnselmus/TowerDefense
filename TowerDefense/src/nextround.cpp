#include "nextround.h"
#include "game.h"

extern Game* game;


NextRound::NextRound(QGraphicsItem *parent) {


    setRect(0, 0, 200, 50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor(222,114, 42));
    setBrush(brush);
    setOpacity(0.7);


    soundEffect = new QMediaPlayer;
    soundEffect->setMedia(QUrl("qrc:/sounds/buttonSelect.mp3"));

    QGraphicsTextItem *text = new QGraphicsTextItem("next round", this);
    text->setFont(QFont("calibri",15));
    int xPos = 100 - text->boundingRect().width()/2;
    int yPos = 25 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    setAcceptHoverEvents(true);
    setFlag(ItemDoesntPropagateOpacityToChildren);

    setPos(975, 725);

}

void NextRound::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (game->wave->getSpawned() >= game->wave->getSize() && game->enemyList->isEmpty() && !game->isOver) {
        soundEffect->play();
        game->startRound();
    }
    else {
        game->soundEffect->setMedia(QUrl("qrc:/sounds/noMoney.mp3"));
        game->soundEffect->play();
    }
}

void NextRound::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    setOpacity(1);
}

void NextRound::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    setOpacity(0.7);
}
