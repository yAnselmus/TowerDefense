#ifndef MENUICON_H
#define MENUICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class MenuIcon: public QGraphicsPixmapItem {

public:
    MenuIcon(QGraphicsItem * parent =0);
    void mousePressEvent (QGraphicsSceneMouseEvent  *event);

};


#endif // MENUICON_H
