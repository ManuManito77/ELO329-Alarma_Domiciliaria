#include "window.h"
#include "windowview.h"

Window::Window()
{

}

//Constructor principal
Window::Window(MagneticSensor * sensor, WindowView * v): magneticSensor(sensor), view(v) {
    isClose=true;
    view->setWindowModel(this);
}

//Método para cambiar de estado
void Window::changeState() {
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