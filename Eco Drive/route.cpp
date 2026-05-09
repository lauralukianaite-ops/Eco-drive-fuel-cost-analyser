#include "route.h"

Route::Route(const QString &start,const QString &destination)
    : infStart(start), infDestination(destination){}

double Route::getDistance() const{
    //temporary, when we connect to API this will be changed
    if(infStart.toLower() == "vilnius" && infDestination.toLower() == "kaunas"){
        return 100.0;
    }
    return 150.0;
}
int Route::getTravelTimeMinutes() const {

    return static_cast<int>(getDistance());
}
