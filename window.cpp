#include "window.h"
#include "windowview.h"

Window::Window()
{

}
Window::Window(MagneticSensor * sensor, WindowView * v): magneticSensor(sensor), view(v) {
    isClose=true;
    view->setWindowModel(this);
}
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