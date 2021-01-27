#ifndef BUILDSLOWINGTOWER_H
#define BUILDSLOWINGTOWER_H

#include "buildtowericon.h"

class BuildSlowingTower: public BuildTowerIcon {
public:
    BuildSlowingTower(QGraphicsItem * t = 0);
    void mousePressEvent (QGraphicsSceneMouseEvent  *event);
};

#endif // BUILDSLOWINGTOWER_H
