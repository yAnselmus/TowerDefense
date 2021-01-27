#include "menuicon.h"
#include "game.h"

extern Game * game;


MenuIcon::MenuIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent) {
    setPixmap(QPixmap(":/images/Cancel-button").scaled(50,50));
}

void MenuIcon::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (game->selectMode) {
        game->selectMode = false;
        game->scene->removeItem(game->towerSelected->menuIcon);
        game->scene->removeItem(game->towerSelected->delIcon);
        delete(game->towerSelected->delIcon);
        delete(game->towerSelected->menuIcon);
        game->towerSelected->attack_area->hide();
    }
}
