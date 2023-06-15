#include "siren.h"
#include "sirenview.h"

Siren::Siren()
{

}

//Constructor principal
Siren::Siren(SirenView * v): view(v) {
    isActive = false;
}

//Acciones para activar y desactivar la sirena
void Siren::play() {
    isActive = true;
    view->setOpenView();
}
void Siren::stop() {
    isActive = false;
    view->setCloseView();
}
bool Siren::getState() {
    return isActive;
}
