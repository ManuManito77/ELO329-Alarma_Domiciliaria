#include <QApplication>
#include <iostream>
#include <fstream>
#include <vector>
#include <QtWidgets>
#include "housewindow.h"
#include "door.h"
#include "doorview.h"
#include "window.h"
#include "windowview.h"
#include "siren.h"
#include "sirenview.h"
#include "central.h"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SirenView *sirenView = new SirenView();
    Siren *siren = new Siren(sirenView);

    Central central(siren);
    HouseWindow gui(&central);  // gui: Graphical User Interface 
    gui.addAlarmHollow(sirenView);
    ifstream fin;

    int nDoors, nWindows;
    if (argc != 2) {
        cout << "Usage: "<<argv[0]<<" <configuration_file>" << endl;
        return -1;
    }
    fin.open(argv[1]);
    if (fin.fail()){
        cout << "Could not read file" << endl;
        return -2;
    }
    cout << "Argument:" << argv[1] << endl;
    fin >> nDoors;
    fin >> nWindows;
    cout << "nDoors:" << nDoors << " nWindows: " << nWindows << endl;

    //Creación de puertas
    for( int i=0; i<nDoors; i++) {
        int x, y, angle, zone;
        fin >> x >> y >> angle >> zone;
        MagneticSensor * sensor = new MagneticSensor(zone);
        DoorView * doorView = new DoorView(x,y,angle, sensor->getView());
        new Door(sensor, doorView);
        central.addNewSensor(sensor);
        gui.addHouseHollow(doorView);
    }

    //Creación de ventanas
    for( int i=0; i<nWindows; i++) {
        int x, y, angle, zone;
        fin >> x >> y >> angle >> zone;
        MagneticSensor * sensor = new MagneticSensor(zone);
        WindowView * windowView = new WindowView(x,y,angle, sensor->getView());
        new Window(sensor, windowView);
        central.addNewSensor(sensor);
        gui.addHouseHollow(windowView);
    }
    gui.show();
    return a.exec();
}
