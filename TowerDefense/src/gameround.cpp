#include "gameround.h"
#include <QFont>


GameRound::GameRound(QGraphicsItem *parent) : QGraphicsTextItem(parent) {
    round = 0;

    setPlainText("Round: " + QString::number(round));
    //QColor color = QColor(235,200,90);
    setDefaultTextColor(Qt::black);
    setFont(QFont("calibri",25));

}

void GameRound::increase() {
    round++;
    setPlainText("Round: " + QString::number(round));

}

int GameRound::getRound() {
    return round;
}
