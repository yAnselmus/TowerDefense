#ifndef MONEY_H
#define MONEY_H

#include <QGraphicsTextItem>

class Money : public QGraphicsPixmapItem {
public:
    Money(QGraphicsItem * parent=0);
    void increase(int amount);
    void decrease(int amount);
    int getMoney();

private:
    int money;
    QGraphicsTextItem* count;
};

#endif // MONEY_H
