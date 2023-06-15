#include "window.h"

Window::Window()
{

}

//Constructor principal
Window::Window(MagneticSensor sensor): magneticSensor(sensor) {
}

//Para cambiar de estado. Homólogo a clase door
void Window::changeState() {
        if (magneticSensor.isClose())
            magneticSensor.setSensorOpen();
        else
            magneticSensor.setSensorClose();
}
MagneticSensor* Window::getSensor() {
    return &magneticSensor;
}
