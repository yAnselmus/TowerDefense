#include "buildmultislowingtower.h"
#include "multislowingtower.h"
#include "game.h"

extern Game* game;

BuildMultiSlowingTower::BuildMultiSlowingTower(QGraphicsItem *t) : BuildTowerIcon(QPixmap(":/images/Slowing-tower.png").scaled(50,50),7,t) { }

void BuildMultiSlowingTower::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (!game->build && !game->selectMode&& game->money->getMoney()>=7 && !game->isOver) {
            game->build = new MultiSlowingTower();
            game->setCursor(QPixmap(":/images/Slowing-tower").scaled(50,50));
    } else {
        game->soundEffect->setMedia(QUrl("qrc:/sounds/noMoney.mp3"));
        game->soundEffect->play();
    }
}




