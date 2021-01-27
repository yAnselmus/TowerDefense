#ifndef DELETETOWERICON_H
#define DELETETOWERICON_H


#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>

class DeleteTowerIcon: public QGraphicsPixmapItem {

public:
    DeleteTowerIcon(QGraphicsItem * parent =0);
    void mousePressEvent (QGraphicsSceneMouseEvent  *event);
    QMediaPlayer *soundEffect;

};

#endif // DELETETOWERICON_H
