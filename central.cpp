#include "central.h"
#include <iostream>

Central::Central(QObject *parent)
    : QObject(parent), timer(new QTimer(this)) {
    connect(timer, SIGNAL(timeout()), this, SLOT(checkZones()));    //chequeo se zonas según activación del timer
    timer ->start(200);     //Periodo del timer en 200ms
}
void Central::addNewSensor(Sensor * ps){
    zones.push_back(ps);        //Se almacenan todos los sensores en esta clase
}

//Chequeo de zonas
void Central::checkZones() {
    bool closeZones[2];
    checkCloseZones(closeZones);
    if (closeZones[0] == false || closeZones[1] == false)
        cout << "Alguna zona está abierta." << endl;
}

//Chequeo de zonas cerradas
void Central::checkCloseZones(bool closeZones[]) {
    closeZones[0] = closeZones[1] = true;
    for (uint i=0; i< zones.size(); i++)
        if(!(zones[i]->isClose())){
            ((i==0)?closeZones[0] = false : closeZones[1] = false); //or (i==(zones.size() - 1))?...
        }
}
Central::~Central(){
    delete timer;
}
