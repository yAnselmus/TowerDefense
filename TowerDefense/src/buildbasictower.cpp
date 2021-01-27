#include "buildbasictower.h"
#include "basictower.h"
#include "game.h"

extern Game* game;

BuildBasicTower::BuildBasicTower(QGraphicsItem *t) : BuildTowerIcon(QPixmap(":/images/Arrow-tower.png").scaled(50,50),5,t) { }

void BuildBasicTower::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (!game->build && !game->selectMode&& game->money->getMoney()>=5 && !game->isOver) {
            game->build = new BasicTower();
            game->setCursor(QPixmap(":/images/Arrow-tower").scaled(50,50));
    } else {
        game->soundEffect->setMedia(QUrl("qrc:/sounds/noMoney.mp3"));
        game->soundEffect->play();
    }
}


