#ifndef SIREN_H
#define SIREN_H

class SirenView;

class Siren
{
private:
    Siren();
public:
    Siren(SirenView * v);
    void play();
    void stop();
    bool getState();
private:
    SirenView * view;
    bool isActive;
};

#endif // SIREN_H
