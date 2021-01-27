#include "money.h"
#include <QFont>

Money::Money(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
    money = 10;
    setPixmap(QPixmap(":/images/Coin-icon").scaled(50,50));

    count = new QGraphicsTextItem(this);
    count->setPlainText(QString::number(money));
    QColor color = QColor(235,200,90);
    count->setDefaultTextColor(color);
    count->setFont(QFont("calibri",35));
    count->setPos(75,-10);

}

void Money::increase(int amount) {
    money += amount;
    count->setPlainText(QString::number(money));
}

void Money::decrease(int amount) {
    money -= amount;
    count->setPlainText(QString::number(money));
}

int Money::getMoney() {
    return money;
}
