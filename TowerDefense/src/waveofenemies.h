#ifndef WAVEOFENEMIES_H
#define WAVEOFENEMIES_H

#include "path.h"
#include "enemy.h"


class WaveOfEnemies
{
public:
    WaveOfEnemies(int roundNumber);
    QList<int> getEnemies();
    int getSize();
    int getSpawned();
    void increaseSpawned();
private:
    int enemiesSpawned_;
    int sizeOfWave_;
    QList<int> enemies;
};

#endif // WAVEOFENEMIES_H
