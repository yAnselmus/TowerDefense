#ifndef BUILDBASICTOWER_H
#define BUILDBASICTOWER_H

#include "buildtowericon.h"

class BuildBasicTower: public BuildTowerIcon {
public:
    BuildBasicTower(QGraphicsItem* t = 0);
    void mousePressEvent (QGraphicsSceneMouseEvent* event);
};

#endif // BUILDBASICTOWER_H
