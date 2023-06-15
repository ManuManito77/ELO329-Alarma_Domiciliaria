#include <iostream>
#include <fstream>
#include <vector>
#include "door.h"
#include "window.h"
#include "central.h"
using namespace std;

int main(int argc, char * argv[]) {
    ifstream fin;
    int nDoors, nWindows, junk;
    Central central;
    vector<Door *> doors;
    vector<Window *> windows;
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
    int zone;
    for (int i=0; i<nDoors; i++) {
        fin >> junk >> junk >> junk >> zone;
        doors.push_back(new Door(zone));
        central.addNewSensor(doors[i]->getSensor());
    }
    for (int i=0; i<nWindows; i++) {
        fin >> junk >> junk >> junk >> zone;
        windows.push_back(new Window(zone));
        central.addNewSensor(windows[i]->getSensor());
    }
    for (unsigned int i=0; i<doors.size(); i++) { //uint : unsigned int
        doors[i]->changeState();
        doors[i]->changeState();
    }
    for (unsigned int i=0; i<windows.size(); i++) { //uint : unsigned int
        windows[i]->changeState();
        windows[i]->changeState();
    }
    central.checkZones();
    doors[0]->changeState();
    central.checkZones();
}
