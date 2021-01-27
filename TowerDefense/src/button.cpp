#include "button.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include <QFont>

Button::Button(QString name, double width, double height, QColor color,int textSize,QGraphicsItem *parent): QGraphicsRectItem(parent) {

    color_ = color;
    setRect(0, 0, width, height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    setBrush(brush);
    setOpacity(0.7);

    soundEffect = new QMediaPlayer;
    soundEffect->setMedia(QUrl("qrc:/sounds/buttonSelect.mp3"));

    text = new QGraphicsTextItem(name,this);
    text->setFont(QFont("calibri",textSize));
    int xPos = width/2 - text->boundingRect().width()/2;
    int yPos = height/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    setAcceptHoverEvents(true);
}


void Button::mousePressEvent(QGraphicsSceneMouseEvent *event) {
        soundEffect->play();
        emit clicked();
}


void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    setOpacity(1);
}


void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    setOpacity(0.7);
}

