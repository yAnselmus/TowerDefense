#ifndef COSTLABEL_H
#define COSTLABEL_H

#include <QGraphicsPixmapItem>


class CostLabel : public QGraphicsPixmapItem{
public:
    CostLabel(int cost, QGraphicsItem * parent=0);
private:
    int cost_;
};

#endif // COSTLABEL_H
