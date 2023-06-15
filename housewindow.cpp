#include "housewindow.h"
#include "ui_housewindow.h"

HouseWindow::HouseWindow(Central *central, QWidget *parent): QMainWindow(parent), ui(new Ui::HouseWindow)
{
    ui->setupUi(this);
    ui->houseRegion->setScene(&interiorScene);
    ui->alarmRegion->setScene(&alarmScene);
    QObject::connect(ui->perimeterButton, SIGNAL(clicked()), central, SLOT(armPerimeter()));
    QObject::connect(ui->disarmButton, SIGNAL(clicked()), central, SLOT(disarm()));
    QObject::connect(central, SIGNAL(showMessage(QString)), this, SLOT(showMessage(QString)));
}
void HouseWindow::showMessage(const QString& message) {
    ui->display->clear(); // Elimina el texto anterior
    ui->display->append(message); // Agrega el nuevo mensaje
}
void HouseWindow::addHouseHollow(QGraphicsItemGroup * compoundItem){
    interiorScene.addItem(compoundItem);
}
void HouseWindow::addAlarmHollow(QGraphicsItemGroup * compoundItem){
    alarmScene.addItem(compoundItem);
}
HouseWindow::~HouseWindow()
{
    delete ui;
}

