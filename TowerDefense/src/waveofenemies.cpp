#include "waveofenemies.h"
#include "QDebug"


WaveOfEnemies::WaveOfEnemies(int roundNumber) {
//    1 = normal enemy
//    2 = fast enemy
//    3 = splitting enemy
//    else = slow enemy

    srand (time(NULL));
    enemiesSpawned_ = 0;

    if (roundNumber == 1) {

        for (int i = 0; i <5; i++) {
            enemies << 1 << 1 << 1;
        }
        sizeOfWave_ = enemies.size();

    } else if (roundNumber == 2) {

        for (int i = 0; i <5; i++) {
        enemies << 1 << 2 << 1;
        }
        sizeOfWave_ = enemies.size();

    } else if (roundNumber == 3) {

        for (int i = 0; i <5; i++) {
        enemies << 1 << 2 << 3;
        }
        sizeOfWave_ = enemies.size();

    } else if (roundNumber == 4) {

        for (int i = 0; i <5; i++) {
        enemies << 2 << 4 << 2;
        }
        sizeOfWave_ = enemies.size();

    } else if (roundNumber == 5) {

        for (int i = 0; i <5; i++) {
        enemies << 1 << 2 << 3 << 4 << 2;
        }
        sizeOfWave_ = enemies.size();

    } else {

        for (int i = 0; i < 5*roundNumber; i++) {
        enemies << rand() % 4;
        }
        sizeOfWave_ = enemies.size();

    }

}

QList<int> WaveOfEnemies::getEnemies() {
    return enemies;
}

int WaveOfEnemies::getSize() {
    return sizeOfWave_;
}

int WaveOfEnemies::getSpawned() {
    return enemiesSpawned_;
}

void WaveOfEnemies::increaseSpawned() {
    enemiesSpawned_++;
}
