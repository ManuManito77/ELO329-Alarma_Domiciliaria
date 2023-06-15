#include "central.h"
#include <iostream>
using namespace std;
Central::Central()
{

}
void Central::addNewSensor(MagneticSensor* sensor){
    sensors.push_back(sensor);  //Para almacenar todos los sensores
}

//Para chequeo de zonas
void Central::checkZones(){
    bool zonesClosed = true;
    for (unsigned int i=0; i<sensors.size(); i++) { //uint : unsigned int
        if(!(sensors[i]->isClose())){
            zonesClosed = false;
        }
    }
    cout << (zonesClosed?"Zonas Cerradas":"Alguna zona está abierta") << endl;
}