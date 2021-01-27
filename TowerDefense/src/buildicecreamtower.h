#ifndef BUILDICECREAMTOWER_H
#define BUILDICECREAMTOWER_H

#include "buildtowericon.h"

class BuildIceCreamTower: public BuildTowerIcon {
public:
    BuildIceCreamTower(QGraphicsItem* t = 0);
    void mousePressEvent (QGraphicsSceneMouseEvent* event);
};

#endif // BUILDICECREAMTOWER_H
