#include "siren.h"
#include "sirenview.h"

Siren::Siren()
{

}
Siren::Siren(SirenView * v): view(v) {
    isActive = false;
}
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
