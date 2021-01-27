#ifndef NEXTROUND_H
#define NEXTROUND_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>

class NextRound: public QGraphicsRectItem {

public:
    NextRound(QGraphicsItem* parent=NULL);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

private:
    QMediaPlayer *soundEffect;
};

#endif // NEXTROUND_H
