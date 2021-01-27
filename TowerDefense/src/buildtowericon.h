#ifndef BUILDTOWERICON_H
#define BUILDTOWERICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <tower.h>
#include <costlabel.h>

class BuildTowerIcon: public QGraphicsPixmapItem {

public:
    BuildTowerIcon(QPixmap towerIcon, int cost, QGraphicsItem * parent =0);
    virtual void mousePressEvent (QGraphicsSceneMouseEvent  *event) =0; //implemented in the subclasses
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

private:
    QPixmap towerIcon;
    CostLabel * cl;

};

#endif // BUILDTOWERICON_H
