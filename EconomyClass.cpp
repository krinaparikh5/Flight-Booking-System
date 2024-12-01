#include "EconomyClass.h"
#include <QStringList>
#include <QRandomGenerator>
EconomyClass::EconomyClass()
{
}

QStringList EconomyClass::getClassAmenities()
{
    return QStringList
    {    //list of amenities given in economy class
        "-Complimentary non-alcoholic beverages",
        "-Access to in-flight entertainment (screens or app)",
        "-Overhead storage for carry-on luggage",
        "-Economy priority check-in for select passengers",
        "-Affordable ticket pricing"
    };
}
int EconomyClass::seatsAvailable()
{
    //randomly decided seat availability in economyClass
    return QRandomGenerator::global()->bounded(1,180);
}
EconomyClass::~EconomyClass(){

}