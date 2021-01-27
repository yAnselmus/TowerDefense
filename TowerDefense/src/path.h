#ifndef PATH_H
#define PATH_H

#include <QList>
#include <QPointF>

class Path
{
public:
    Path();
    QList<QPointF> getDestinations();
    QList<QPointF> getDestinationsForEnemy();
    void generateRandomDests();
private:
    QList<QPointF> destinations;
};

#endif // PATH_H
