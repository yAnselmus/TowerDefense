#include "costlabel.h"
#include <QFont>
#include <QGraphicsRectItem>
#include "QBrush"


CostLabel::CostLabel(int cost, QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
    cost_ = cost;
    setPixmap(QPixmap(":/images/Coin-icon").scaled(20,20));
    setPos(7,60);

    QGraphicsRectItem *background = new QGraphicsRectItem(-12,-5,60,30,this);
    background->setFlag(ItemStacksBehindParent);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkGray);
    background->setBrush(brush);
    background->setOpacity(0.4);

    QGraphicsTextItem *count = new QGraphicsTextItem(this);
    count->setPlainText(QString::number(cost_));
    QColor color = QColor(235,200,90);
    count->setDefaultTextColor(color);
    count->setFont(QFont("calibri",15));
    count->setPos(20,-7);

}
