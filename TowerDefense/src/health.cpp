#include "health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
    health = 10;
    setPixmap(QPixmap(":/images/Health-icon2").scaled(50,50));

    count = new QGraphicsTextItem(this);
    count->setPlainText(QString::number(health));
    QColor color = QColor(191,6,6);
    count->setDefaultTextColor(color);
    count->setFont(QFont("calibri",35));
    count->setPos(75,-10);

}

void Health::decrease(int amount) {
    health-=amount;
    count->setPlainText(QString::number(health));
}

int Health::getHealth() {
    return health;
}
