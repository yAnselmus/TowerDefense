#include "buildtowericon.h"
#include "game.h"
#include <QGraphicsRectItem>
#include <QRectF>
#include <QBrush>

extern Game * game;


BuildTowerIcon::BuildTowerIcon(QPixmap towerIcon, int cost, QGraphicsItem *parent): QGraphicsPixmapItem(parent) {

    //setFlag(ItemDoesntPropagateOpacityToChildren);
    QGraphicsRectItem* rect = new QGraphicsRectItem(-5,-5,60,60,this);
    rect->setFlag(ItemStacksBehindParent);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);
    rect->setBrush(brush);
    rect->setOpacity(0.4);
    setPixmap(towerIcon);
    cl = new CostLabel(cost, this);
}

// These dont work, no idea why
void BuildTowerIcon::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    setOpacity(0.1);

}

void BuildTowerIcon::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    setOpacity(1);
}
