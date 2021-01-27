#include "buildicecreamtower.h"
#include "icecreamtower.h"
#include "game.h"

extern Game* game;

BuildIceCreamTower::BuildIceCreamTower(QGraphicsItem *t) : BuildTowerIcon(QPixmap(":/images/Icecream-tower.png").scaled(50,50),3,t) { }

void BuildIceCreamTower::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (!game->build && !game->selectMode&& game->money->getMoney()>=3 && !game->isOver) {
            game->build = new IceCreamTower();
            game->setCursor(QPixmap(":/images/Icecream-tower").scaled(50,50));
    } else {
        game->soundEffect->setMedia(QUrl("qrc:/sounds/noMoney.mp3"));
        game->soundEffect->play();
    }
}

