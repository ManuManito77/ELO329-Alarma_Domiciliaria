#include "windowview.h"
#include <QBrush>
WindowView::WindowView(int x, int y, int angle, MagneticSensorView * mv) {
    makeWindowView(); 
    mv->setParentItem(this);
    installMagneticSensor(*mv);
    magnet = &(mv->getMagnetView());
    QTransform transform;
    transform.translate(x,y);
    transform.rotate(angle);
    setTransform(transform);
}
void WindowView::makeWindowView(){
    QGraphicsRectItem * origenPillar = new QGraphicsRectItem(0, 0, 16, 16, this);
    origenPillar->setBrush(Qt::blue); 
    switchPillar = new QGraphicsRectItem(336, 0, 16, 16, this);
    switchPillar->setBrush(Qt::blue);
    QGraphicsRectItem * fixedGlass = new QGraphicsRectItem(16, 0, 160, 8, this);
    fixedGlass->setBrush(QColor(180, 210, 230)); //Ventana = QColor(180, 210, 230)
    slidingGlass = new QGraphicsRectItem(176, 8, 160, 8, this);
    slidingGlass->setBrush(QColor(180, 210, 230));
    addToGroup(origenPillar);
    addToGroup(switchPillar);
    addToGroup(fixedGlass);
    addToGroup(slidingGlass);
}
void WindowView::setWindowModel(Window * m){
    model=m;
}
void WindowView::installMagneticSensor(MagneticSensorView & mv){
    mv.getMagnetView().setRect(slidingGlass->rect().right()-mv.getMagnetView().rect().width(),
                                 slidingGlass->rect().bottom(),
                                 mv.getMagnetView().rect().width(),
                                 mv.getMagnetView().rect().height());
    mv.getSwitchView().setRect(switchPillar->rect().left(),
                                 switchPillar->rect().bottom(),
                                 mv.getSwitchView().rect().width(),
                                 mv.getSwitchView().rect().height());
    addToGroup(&mv.getMagnetView());
    addToGroup(&mv.getSwitchView());
}
void WindowView::setOpen(){ 
    QPointF posicionActual = slidingGlass->pos();
    QPointF nuevaPosicion = QPointF(posicionActual.x() - slidingGlass->rect().width(), posicionActual.y());
    slidingGlass->setPos(nuevaPosicion);
    magnet->setPos(nuevaPosicion);
}
void WindowView::setClose(){
    QPointF posicionActual = slidingGlass->pos();
    QPointF nuevaPosicion = QPointF(posicionActual.x() + slidingGlass->rect().width(), posicionActual.y());
    slidingGlass->setPos(nuevaPosicion);
    magnet->setPos(nuevaPosicion);
}
void WindowView::mousePressEvent(QGraphicsSceneMouseEvent * event){
    if (model!= NULL && event->button()==Qt::LeftButton)
        model->changeState();
}
WindowView::~WindowView(){
    delete slidingGlass;
    delete switchPillar;
}
