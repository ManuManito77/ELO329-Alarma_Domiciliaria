#ifndef SIRENVIEW_H
#define SIRENVIEW_H

#include <QObject>
#include <QTimer>
#include <QGraphicsItemGroup>
#include <QGraphicsRectItem>
#include <QGraphicsPolygonItem>
#include "siren.h"


class SirenView : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
public:
    SirenView();
    void setCloseView();
    void setOpenView();
    ~SirenView();
private slots:
    void changeColor();
    void resetColor();
private:
    void makeSirenView();
    QGraphicsPolygonItem *sirenView;
    QTimer *timer;
};


#endif // SIRENVIEW_H
