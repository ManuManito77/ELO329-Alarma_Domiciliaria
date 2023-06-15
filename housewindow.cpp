#include "housewindow.h"
#include "ui_housewindow.h"

HouseWindow::HouseWindow(Central *central, QWidget *parent): QMainWindow(parent), ui(new Ui::HouseWindow)
{
    ui->setupUi(this);
    ui->houseRegion->setScene(&interiorScene);  //Area de escenario para puertas y ventanas
    ui->alarmRegion->setScene(&alarmScene);     //Area de escenario para botones y sirena

    //Acciones para los botones
    QObject::connect(ui->perimeterButton, SIGNAL(clicked()), central, SLOT(armPerimeter()));    //activar alarma
    QObject::connect(ui->disarmButton, SIGNAL(clicked()), central, SLOT(disarm()));             //desarmar alarma

    //Mostra string en cuadro de texto
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

