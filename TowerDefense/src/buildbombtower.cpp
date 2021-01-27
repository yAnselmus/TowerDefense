#include "buildbombtower.h"
#include "bombtower.h"
#include "game.h"

extern Game* game;

BuildBombTower::BuildBombTower(QGraphicsItem *t) : BuildTowerIcon(QPixmap(":/images/Bomb-tower.png").scaled(50,50),8,t) { }

void BuildBombTower::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (!game->build && !game->selectMode&& game->money->getMoney()>=8 && !game->isOver) {
            game->build = new BombTower();
            game->setCursor(QPixmap(":/images/Bomb-tower").scaled(50,50));
    } else {
        game->soundEffect->setMedia(QUrl("qrc:/sounds/noMoney.mp3"));
        game->soundEffect->play();
    }
}


