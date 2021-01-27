#ifndef BUILDMULTISLOWINGTOWER_H
#define BUILDMULTISLOWINGTOWER_H

#include "buildtowericon.h"

class BuildMultiSlowingTower: public BuildTowerIcon {
public:
    BuildMultiSlowingTower(QGraphicsItem * t = 0);
    void mousePressEvent (QGraphicsSceneMouseEvent  *event);
};

#endif // BUILDMULTISLOWINGTOWER_H
