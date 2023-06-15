#ifndef CENTRAL_H
#define CENTRAL_H
#include <QObject>
#include <vector>
#include <QTimer>
#include <QString>
#include "sensor.h"
#include "siren.h"
using namespace std; //needed by vector<>

class Central : public QObject
{
    Q_OBJECT
public:
    explicit Central(Siren *s, QObject *parent = nullptr);
    void addNewSensor(Sensor * ps);
    ~Central();
public slots:
    void armPerimeter();
    void disarm();
private slots:
    void checkZones();
signals:
    void showMessage(const QString& message);
private:
    void checkCloseZones(bool closeZones[]);
    vector<Sensor *> zones;  // keep references to all sensors already installed in doors and windows.
    QTimer * timer;
    Siren * siren;
    bool isArmed;   //variable para controlar la activación de la alarma
};

#endif // CENTRAL_H
