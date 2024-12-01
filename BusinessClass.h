#ifndef FLIGHTBOOKINGSYSTEM_BUSINESSCLASS_H
#define FLIGHTBOOKINGSYSTEM_BUSINESSCLASS_H
#include "BookingClass.h"
#include <QStringList>
//inherits BookingClass
class BusinessClass : public BookingClass
{
public:
    BusinessClass();
    //override functions from the abstract virtual function in their base class
    QStringList getClassAmenities() override;
    int seatsAvailable() override;
    ~BusinessClass() override;
};
#endif //FLIGHTBOOKINGSYSTEM_BUSINESSCLASS_H
