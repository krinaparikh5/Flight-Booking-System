#ifndef FLIGHTBOOKINGSYSTEM_FIRSTCLASS_H
#define FLIGHTBOOKINGSYSTEM_FIRSTCLASS_H
#include "BookingClass.h"
#include <QStringList>
//inherits BookingClass
class FirstClass : public BookingClass
{
public:
    FirstClass();
    //override functions from the abstract virtual function in their base class
    QStringList getClassAmenities() override;
    int seatsAvailable() override;
    ~FirstClass() override;
};
#endif //FLIGHTBOOKINGSYSTEM_FIRSTCLASS_H

