#include "deletetowericon.h"
#include "game.h"

extern Game * game;


DeleteTowerIcon::DeleteTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent) {
    setPixmap(QPixmap(":/images/Delete-button").scaled(50,50));
    soundEffect = new QMediaPlayer();
    soundEffect->setMedia(QUrl("qrc:/sounds/delete.mp3"));

}

void DeleteTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (game->selectMode) {
        soundEffect->play();
        game->money->increase(game->towerSelected->sellPrice);

        game->scene->removeItem(game->towerSelected->delIcon);
        game->scene->removeItem(game->towerSelected);

        delete(game->towerSelected->delIcon);
        delete(game->towerSelected->attack_area);
        delete(game->towerSelected->soundEffect);
        delete(game->towerSelected);

        game->selectMode = false;
    }
}
