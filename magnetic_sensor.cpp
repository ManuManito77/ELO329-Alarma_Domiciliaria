#include "magnetic_sensor.h"

MagneticSensor::MagneticSensor(int z) : Sensor(z) {
}
void MagneticSensor::setSensorOpen() {
    Sensor::setClose(false);
}
void MagneticSensor::setSensorClose() {
    Sensor::setClose(true);
}
