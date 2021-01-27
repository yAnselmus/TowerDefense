#include "buildslowingtower.h"
#include "slowingtower.h"
#include "tower.h"
#include "game.h"

extern Game* game;

BuildSlowingTower::BuildSlowingTower(QGraphicsItem *t) : BuildTowerIcon(QPixmap(":/images/SlowingShooting-tower.png").scaled(50,50),5,t) { }

void BuildSlowingTower::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (!game->build && !game->selectMode && game->money->getMoney()>=5 && !game->isOver) {
            game->build = new SlowingTower();
            game->setCursor(QPixmap(":/images/SlowingShooting-tower").scaled(50,50));
    } else {
        game->soundEffect->setMedia(QUrl("qrc:/sounds/noMoney.mp3"));
        game->soundEffect->play();
    }
}


