#ifndef FLIGHTBOOKINGSYSTEM_BOOKINGCLASS_H
#define FLIGHTBOOKINGSYSTEM_BOOKINGCLASS_H
#include <QString>

class BookingClass {
public:
    BookingClass();
    // Common method for all booking classes
    float randomPrice();
    //abstract virtual function for both seatsAvailable and getClassAmenities
    virtual int seatsAvailable() = 0;
    virtual QStringList getClassAmenities() = 0;
    virtual ~BookingClass() = default;
};
#endif //FLIGHTBOOKINGSYSTEM_BOOKINGCLASS_H
