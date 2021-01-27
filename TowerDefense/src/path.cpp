#include "path.h"
#include <stdlib.h>
#include "QDebug"
#include <time.h>



Path::Path() {

    destinations << QPointF(0,150) << QPointF(200,150) << QPointF(200,600) << QPointF(800,600) << QPointF(800,0);

}



QList<QPointF> Path::getDestinations() {

    return destinations;

}



QList<QPointF> Path::getDestinationsForEnemy() {

    QList<QPointF> EnemyDests;

    for(int i = 0; i < destinations.size(); i++) {

        QPointF a = QPointF(destinations[i].x()-25,destinations[i].y()-25);

        EnemyDests << a;

    }

    return EnemyDests;

}



void Path::generateRandomDests() {

    srand (time(NULL));

    int amountOfDests = 5;

    int pathInPixels = 0;



    QList<QPointF> Dests;





    for(int i = 0; i < amountOfDests; i++) {



        if (i==0) {

            int randY = rand() % 500 + 201;

            Dests << QPointF(0, randY);

            pathInPixels = randY;

        }



        else if (i == amountOfDests-1) {

            Dests << QPointF(Dests[i-1].x(), 0);

        }



        else if (i%2 != 0) {

            bool flag = true;

            int randX = 0;

            while (flag) {

                randX = rand() % 700 + 51;

                if (std::abs(randX-Dests[i-1].x())>200) { flag  = false; }

            }

            Dests << QPointF(randX, Dests[i-1].y());

        }



        else {

            bool flag = true;

            int randY = 0;

            while (flag) {

                randY = rand() % 700 + 51;

                if (std::abs(randY-Dests[i-1].y()) > 200) { flag  = false; }

            }

            Dests << QPointF(Dests[i-1].x(), randY);

        }

    }



    destinations = Dests;

}
