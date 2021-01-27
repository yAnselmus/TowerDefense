#ifndef GAMEROUND_H
#define GAMEROUND_H

#include <QGraphicsTextItem>

class GameRound: public QGraphicsTextItem {
public:
    GameRound(QGraphicsItem * parent=0);
    void increase();
    int getRound();

private:
    int round;
};


#endif // GAMEROUND_H
