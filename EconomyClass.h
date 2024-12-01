#ifndef FLIGHTBOOKINGSYSTEM_ECONOMYCLASS_H
#define FLIGHTBOOKINGSYSTEM_ECONOMYCLASS_H
#include "BookingClass.h"
#include <QStringList>
//inherits BookingClass
class EconomyClass : public BookingClass
{
public:
    EconomyClass();
    //override functions from the abstract virtual function in their base class
    QStringList getClassAmenities() override;
    int seatsAvailable() override;
    ~EconomyClass() override;
};
#endif //FLIGHTBOOKINGSYSTEM_ECONOMYCLASS_H
