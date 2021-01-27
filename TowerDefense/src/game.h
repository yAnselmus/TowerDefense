#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include "money.h"
#include "health.h"
#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include "tower.h"
#include "gameround.h"
#include "path.h"
#include <QTimer>
#include "waveofenemies.h"
#include <QtMultimedia/QMediaPlayer>
#include "button.h"
#include "enemy.h"


class Game: public QGraphicsView {
    Q_OBJECT

public:
    Game(QWidget* parent = NULL);
    void setCursor(QPixmap pic);
    void mouseMoveEvent (QMouseEvent * event);
    void mousePressEvent(QMouseEvent * event);
    void createPath();
    void gameOver();
    void bootGame();
    ~Game();

    QGraphicsScene * scene;
    Money * money;
    Health * health;
    GameRound * round;
    Path *path;
    WaveOfEnemies *wave;

    QMediaPlayer *soundEffect;      // for single sounds
    QMediaPlayer *player;           // for bavkgorund music

    QGraphicsItemGroup * cursor;
    QGraphicsPixmapItem * cursorpic;
    QPixmap formerPixmap;       // helps when building a tower
    QGraphicsEllipseItem * cursorrange;

    bool collides;
    Tower* build;               // a tower is being built if this is NOT nullptr
    Tower* towerSelected;       // tells which tower is selected
    bool selectMode;            // if true, a tower is selected
    bool isOver;                // a flag to point out if game is over

    QList<Enemy*>* enemyList;   // a list of all the living enemies

    QTimer *spawnTimer;         // specifies the time between enemy spawns


public slots:
    void start();
    void startRound();
    void spawnEnemy();
    void mapSelect();
    void randomMap();
    void displayMainMenu();
    void backToMainMenu();

private:
    void drawInfo();
};

#endif // GAME_H
