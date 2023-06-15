#include "central.h"
#include <iostream>

using namespace std;


//Constructor principal
Central::Central(Siren *s, QObject *parent)
    : QObject(parent), timer(new QTimer(this)) {
    connect(timer, SIGNAL(timeout()), this, SLOT(checkZones()));    //Chequea las zonas según se active el timer
    timer ->start(200);     //periodo del timer cada 200ms
    isArmed = false;
    this->siren = s;
}


void Central::addNewSensor(Sensor * ps){
    zones.push_back(ps);
}

//Condiciones para activar la alarma
void Central::armPerimeter(){
    bool closeZones[2];
    checkCloseZones(closeZones);
    if(!isArmed){
        if(closeZones[0] && closeZones[1]){
            isArmed = true;
            emit showMessage("Perímetro armado");
        }
        else{
            emit showMessage(QString("Open zone(s): %1, %2").arg(closeZones[0]?"-":"0").arg(closeZones[1]?"-":"1"));
        }
    }
}

//Desactivar alarma
void Central::disarm(){
    isArmed = false;
    siren->stop();
    emit showMessage("Perímetro desarmado");
}

//Método para chequear las zonas
void Central::checkZones() {
    bool closeZones[2];
    checkCloseZones(closeZones);
    if(isArmed){
        if ((closeZones[0] == false || closeZones[1] == false) && siren->getState() == false){
            emit showMessage("Alarma Activada");
            siren->play();
        }
    }
}

//Metodo para chequear zonas cerradas
void Central::checkCloseZones(bool closeZones[]) {
    closeZones[0] = closeZones[1] = true;
    for (uint i=0; i< zones.size(); i++)
        if(!(zones[i]->isClose())){
            ((i==0)?closeZones[0] = false : closeZones[1] = false); 
        }
}
Central::~Central(){
    delete timer;
}
