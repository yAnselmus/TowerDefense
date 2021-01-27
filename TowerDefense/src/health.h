#ifndef HEALTH_H
#define HEALTH_H


#include <QGraphicsTextItem>


class Health : public QGraphicsPixmapItem {
public:
    Health(QGraphicsItem * parent=0);
    void decrease(int amount);
    int getHealth();


private:
    int health;
    QGraphicsTextItem* count; // The visual counter
};

#endif // HEALTH_H
