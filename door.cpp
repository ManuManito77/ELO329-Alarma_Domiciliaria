#include "door.h"
#include "doorview.h"

Door::Door()
{

}
//Constructor principal
Door::Door(MagneticSensor * sensor, DoorView * v): magneticSensor(sensor), view(v) {
    isClose=true;
    view->setDoorModel(this);
}

//Cambio de estado abieto-cerrado
void Door::changeState() {
    if (isClose) {
       isClose = false;
       view->setOpen();
       magneticSensor->setSensorOpen();
    } else {
       isClose = true;
       view->setClose();
       magneticSensor->setSensorClose();
    }
}

