#ifndef BUILDBOMBTOWER_H
#define BUILDBOMBTOWER_H

#include "buildtowericon.h"

class BuildBombTower: public BuildTowerIcon {
public:
    BuildBombTower(QGraphicsItem * t = 0);
    void mousePressEvent (QGraphicsSceneMouseEvent  *event);
};

#endif // BUILDBOMBTOWER_H
