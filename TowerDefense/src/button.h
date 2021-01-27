#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>


class Button: public QObject, public QGraphicsRectItem {
    Q_OBJECT

public:
    Button(QString name, double width, double height, QColor color,int textSize, QGraphicsItem* parent=NULL);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

signals:
    void clicked();

private:
    QGraphicsTextItem* text;
    QColor color_;
    QMediaPlayer *soundEffect;

};

#endif // BUTTON_H
