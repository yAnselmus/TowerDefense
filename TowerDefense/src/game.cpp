#include "game.h"
#include "tower.h"
#include "buildtowericon.h"
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include "buildbasictower.h"
#include "buildbombtower.h"
#include "buildslowingtower.h"
#include "buildmultislowingtower.h"
#include "buildicecreamtower.h"
#include "costlabel.h"
#include "basictower.h"
#include "slowingtower.h"
#include "bombtower.h"
#include "multislowingtower.h"
#include "icecreamtower.h"
#include <QtMultimedia/QMediaPlaylist>
#include "nextround.h"
#include "smallenemy.h"
#include "slowenemy.h"
#include "splittingenemy.h"
#include "fastenemy.h"

Game::Game(QWidget *parent) : QGraphicsView() {

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1200,800);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200,800);

    cursor = nullptr;
    build = nullptr;
    collides = true;
    selectMode = false;
    enemyList = new QList<Enemy*>;
    soundEffect = new QMediaPlayer;
    soundEffect->setVolume(70);
    isOver = false;
    path = new Path();

    setMouseTracking(true);

    // Setting up the background music

    QMediaPlaylist *music = new QMediaPlaylist();
    music->addMedia(QUrl("qrc:/sounds/bensound-epic.mp3"));
    music->setPlaybackMode(QMediaPlaylist::Loop);

    player = new QMediaPlayer;
    player->setPlaylist(music);
    player->setVolume(10);

}

void Game::setCursor(QPixmap pic) {
    if (cursor) {
        scene->removeItem(cursor);
        delete cursor;
    }
    cursor = new QGraphicsItemGroup();  //cursor on ryhmä johon voi lisätä graphicitemeja. Tassa range ympyra ja kuva
    cursorpic = new QGraphicsPixmapItem();
    cursorrange = build->getAttackRange();
    cursorpic->setPixmap(pic);
    formerPixmap = pic;
    cursor->addToGroup(cursorpic);
    cursor->addToGroup(cursorrange);
    scene->addItem(cursor);
    soundEffect->setMedia(QUrl("qrc:/sounds/selectingTower.mp3"));
    soundEffect->play();
}

void Game::mouseMoveEvent(QMouseEvent *event) {
    if (cursor) {
        QList<QGraphicsItem *> colliding = cursorpic->collidingItems();

        if(!collides) {
            for(int i = 0; i < colliding.size(); i++) {
                if(typeid(*(colliding[i])) == typeid(BasicTower) ||
                   typeid(*(colliding[i])) == typeid(BombTower) ||
                   typeid(*(colliding[i])) == typeid(SlowingTower) ||
                   typeid(*(colliding[i])) == typeid(MultiSlowingTower) ||
                   typeid(*(colliding[i])) == typeid(IceCreamTower) ||
                   typeid(*(colliding[i])) == typeid(QGraphicsRectItem) ||
                   typeid(*(colliding[i])) == typeid(QGraphicsLineItem)) {
                        cursorpic->setPixmap(QPixmap(":/images/Place-icon.png").scaled(50,50));
                        collides = true;
                        break;
                }
            }
        }
        if(collides) {
            for(int i = 0; i < colliding.size(); i++) {
                if(typeid(*(colliding[i])) == typeid(BasicTower) ||
                   typeid(*(colliding[i])) == typeid(BombTower) ||
                   typeid(*(colliding[i])) == typeid(SlowingTower) ||
                   typeid(*(colliding[i])) == typeid(MultiSlowingTower) ||
                   typeid(*(colliding[i])) == typeid(IceCreamTower) ||
                   typeid(*(colliding[i])) == typeid(QGraphicsRectItem) ||
                   typeid(*(colliding[i])) == typeid(QGraphicsLineItem)) {
                        break;
                } else if(i + 1 == colliding.size()) {
                        cursorpic->setPixmap(formerPixmap);
                        collides = false;
                }
            }
        }
        cursor->setPos(event->pos().rx() - 25, event->pos().ry() - 25); //Keskittaa kursorin hiiren keskelle. 25 on puolet 50 joka on skaalattu kuva
    } else {
        QGraphicsView::mouseMoveEvent(event);
    }
}

void Game::mousePressEvent(QMouseEvent *event) {
    if (build && !collides && event->button() == Qt::LeftButton) {
        money->decrease(build->cost);
        scene->addItem(build);
        build->setPos(event->pos().rx() - 25, event->pos().ry() - 25);  //Keskittaa kursorin hiiren keskelle. 25 on puolet 50 joka on skaalattu kuva
        scene->removeItem(cursor);
        cursor = nullptr;
        build = nullptr;
        collides = true;
        soundEffect->setMedia(QUrl("qrc:/sounds/buying.mp3"));
        soundEffect->play();
    } else if ( build && event->button() == Qt::RightButton) {
        scene->removeItem(cursor);
        cursor = nullptr;
        build = nullptr;
        collides = true;
        soundEffect->setMedia(QUrl("qrc:/sounds/selectingTower.mp3"));
        soundEffect->play();
    } else if (selectMode && event->button() == Qt::RightButton) {
        selectMode = false;
        scene->removeItem(towerSelected->delIcon);
        delete(towerSelected->delIcon);
        towerSelected->attack_area->hide();
        soundEffect->setMedia(QUrl("qrc:/sounds/cancel.mp3"));
        soundEffect->play();
    }
    else {
        QGraphicsView::mousePressEvent(event);
    }
}

void Game::displayMainMenu() {

    QGraphicsTextItem * titleText = new QGraphicsTextItem(QString("Tower Defense"));
    QFont titleFont("comic sans", 50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos =150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    Button * playButton = new Button(QString("Play"), 150, 50 , Qt::green,20);
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos, byPos);
    connect( playButton, SIGNAL( clicked() ), this, SLOT( mapSelect() ) );
    scene->addItem(playButton);

    Button * quitButton = new Button(QString("Quit"), 150, 50, Qt::green,20);
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos, qyPos);
    connect(quitButton, SIGNAL( clicked() ), this, SLOT( close() ) );
    scene->addItem(quitButton);

}

void Game::backToMainMenu() {
    bootGame();
    player->stop();
    setBackgroundBrush(QBrush(Qt::white));
    displayMainMenu();
    path = new Path();
}

void Game::createPath() {

    QList<QPointF> destinations = path->getDestinations();
    int n = path->getDestinations().size()-1;

    for (int i = 0; i<n; i++) {
        QLineF line(destinations[i],destinations[i+1]);
        QGraphicsLineItem * lineItem = new QGraphicsLineItem(line);


        QPen pen;
        QBrush brush(QPixmap(":/images/Path2"));
        pen.setWidth(45);
        pen.setColor(Qt::black);
        pen.setBrush(brush);
        lineItem->setPen(pen);

        scene->addItem(lineItem);

    }
}

void Game::gameOver() {
     isOver = true;
     spawnTimer->disconnect();

    // Sets the box
    QGraphicsRectItem* box = new QGraphicsRectItem(275,this->height()/2-150,400,375);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    box->setBrush(brush);
    scene->addItem(box);

    // Sets the "Game Over" -text
    QGraphicsTextItem* text = new QGraphicsTextItem(box);
    text->setPlainText("Game Over!");
    text->setDefaultTextColor(Qt::white);
    text->setFont(QFont("calibri",50));
    text->setPos(305,270);

    // Sets the "Retry" -button
    Button * retryButton = new Button(QString("Retry"), 150, 50 , Qt::white,20);
    retryButton->setPos(400, 375);
    connect( retryButton, SIGNAL( clicked() ), this, SLOT( start() ) );
    scene->addItem(retryButton);

    // Sets the "Quit" -button
    Button * quitButton = new Button(QString("Quit"), 150, 50, Qt::white,20);
    quitButton->setPos(400, 450);
    connect(quitButton, SIGNAL( clicked() ), this, SLOT( close() ) );
    scene->addItem(quitButton);

    // Sets "Main menu" -button
    Button * menuButton = new Button(QString("Main Menu"), 150, 50, Qt::white,20);
    menuButton->setPos(400, 525);
    connect(menuButton, SIGNAL( clicked() ), this, SLOT( backToMainMenu() ) );
    scene->addItem(menuButton);

}

void Game::bootGame() {

    scene->clear();
    money = nullptr;
    health = nullptr;
    round = nullptr;
    wave = nullptr;

    cursor = nullptr;
    cursorpic = nullptr;
    cursorrange = nullptr;

    collides = true;
    build = nullptr;
    towerSelected = nullptr;
    selectMode = false;
    isOver = false;

    while(!enemyList->empty()) {
        enemyList->removeFirst();
    }

    spawnTimer = nullptr;

}

Game::~Game() {

    delete scene;
    delete money;
    delete health;
    delete round;
    delete path;
    delete wave;
    delete soundEffect;
    delete player;

    delete cursor;
    delete cursorpic;
    delete cursorrange;

    delete build;
    delete towerSelected;

    for (auto it : *enemyList) {
        delete it;
    }

    delete spawnTimer;
}

void Game::randomMap() {
 path->generateRandomDests();
 start();
}

void Game::mapSelect() {

    scene->clear();

    QGraphicsTextItem * titleText = new QGraphicsTextItem(QString("Select a Map"));
    QFont titleFont("comic sans", 50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos =50;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    Button * basic = new Button(QString("Basic Map"), 150, 50 , Qt::green,20);
    int bxPos = this->width()/4 - basic->boundingRect().width()/2;
    int byPos = 675;
    basic->setPos(bxPos, byPos);
    connect( basic, SIGNAL( clicked() ), this, SLOT( start() ) );
    scene->addItem(basic);

    QGraphicsPixmapItem *basicMap = new QGraphicsPixmapItem();
    basicMap->setPixmap(QPixmap(":/images/basicMap.png").scaled(472,399));
    basicMap->setPos(width()/4-236,225);
    scene->addItem(basicMap);
    basicMap->show();

    Button * random = new Button(QString("Random Map"), 150, 50, Qt::green,20);
    int qxPos = this->width()/4*3 - random->boundingRect().width()/2;
    int qyPos = 675;
    random->setPos(qxPos, qyPos);
    connect(random, SIGNAL( clicked() ), this, SLOT( randomMap() ) );
    scene->addItem(random);

    QGraphicsPixmapItem *randomMap = new QGraphicsPixmapItem();
    randomMap->setPixmap(QPixmap(":/images/randomMap.png").scaled(472,399));
    randomMap->setPos(width()/4*3-236,225);
    scene->addItem(randomMap);
    randomMap->show();

}

void Game::startRound() {

    round->increase();
    wave = new WaveOfEnemies(round->getRound());
    connect(spawnTimer, SIGNAL(timeout()), this, SLOT(spawnEnemy()) );
    spawnTimer->start(1000);

}

void Game::spawnEnemy() {
    if(!isOver && !wave->getEnemies().isEmpty()) {
        Enemy* enemy;

        if( wave->getEnemies()[wave->getSpawned()] == 1 ) {
            enemy = new Enemy(path->getDestinationsForEnemy());

        } else if (wave->getEnemies()[wave->getSpawned()] == 2 ) {
            enemy = new FastEnemy(path->getDestinationsForEnemy());

        } else if (wave->getEnemies()[wave->getSpawned()] == 3 ) {
            enemy = new SplittingEnemy(path->getDestinationsForEnemy());

        } else {    // the case of slow enemy
            enemy = new SlowEnemy(path->getDestinationsForEnemy());
        }

        enemyList->append(enemy);
        scene->addItem(enemy);

        wave->increaseSpawned();

        if (wave->getSpawned() >= wave->getSize()) {
            spawnTimer->disconnect();
        }
    }
}

void Game::start() {

    if (isOver) {
        bootGame();
    }

    player->play();
    scene->clear();
    setBackgroundBrush(QBrush(QImage(":/images/BackgroundSimple.png")));

    drawInfo();
    createPath();

    spawnTimer = new QTimer(this);
    wave = new WaveOfEnemies(0);

}

void Game::drawInfo() {

    QGraphicsRectItem *panel = new QGraphicsRectItem(950,0,250,800);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    QColor color = QColor(156,67, 8);
    brush.setColor(color);
    panel->setBrush(brush);
    scene->addItem(panel);

    money= new Money();
    money->setPos(1000,10);
    scene->addItem(money);

    health = new Health();
    health->setPos(1000, 65);
    scene->addItem(health);

    round = new GameRound();
    round->setPos(980, 685);
    scene->addItem(round);

    BuildTowerIcon * ic1 = new BuildBasicTower();
    ic1->setPos(980, 200);
    scene->addItem(ic1);

    BuildTowerIcon * ic2 = new BuildBombTower();
    ic2->setPos(1050, 200);
    scene->addItem(ic2);;

    BuildTowerIcon * ic3 = new BuildSlowingTower();
    ic3->setPos(1120, 200);
    scene->addItem(ic3);

    BuildTowerIcon * ic4 = new BuildMultiSlowingTower();
    ic4->setPos(980, 310);
    scene->addItem(ic4);

    BuildTowerIcon * ic5 = new BuildIceCreamTower();
    ic5->setPos(1050, 310);
    scene->addItem(ic5);

    NextRound* next = new NextRound();
    scene->addItem(next);

}
