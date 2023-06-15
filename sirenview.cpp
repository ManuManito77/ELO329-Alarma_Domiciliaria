#include "sirenview.h"
#include <QBrush>

SirenView::SirenView()
{
    makeSirenView();
}
void SirenView::makeSirenView(){
    sirenView = new QGraphicsPolygonItem(this);
    QPolygonF sirenPolygon;
    sirenPolygon.append(QPointF(0, 0));
    sirenPolygon.append(QPointF(0, 100));
    sirenPolygon.append(QPointF(48, 72));
    sirenPolygon.append(QPointF(64, 72));
    sirenPolygon.append(QPointF(64, 28));
    sirenPolygon.append(QPointF(48, 28));
    sirenView->setPolygon(sirenPolygon);
    sirenView->setBrush(Qt::green);
    addToGroup(sirenView);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(changeColor()));
}
void SirenView::setCloseView(){
    //sirenView->setBrush(Qt::green);
    resetColor();
}
void SirenView::setOpenView(){
    //sirenView->setBrush(Qt::red);
    timer->start(100);
}
void SirenView::changeColor(){
    if (sirenView->brush().color()==Qt::green){
        sirenView->setBrush(Qt::red);
    }else{sirenView->setBrush(Qt::green);}
}
void SirenView::resetColor(){
    timer->stop();
    sirenView->setBrush(Qt::green);
}
SirenView::~SirenView(){
    delete sirenView;
    delete timer;
}

