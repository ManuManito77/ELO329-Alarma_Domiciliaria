#ifndef CENTRAL_H
#define CENTRAL_H
#include <vector>
#include "magnetic_sensor.h"
using namespace std;

class Central
{
public:
    Central();
    void addNewSensor(MagneticSensor* sensor);
    void checkZones();
private:
    vector<MagneticSensor *> sensors;
};


#endif // CENTRAL_H