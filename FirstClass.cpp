#include "FirstClass.h"
#include <QStringList>
#include <QRandomGenerator>
FirstClass::FirstClass()
{

}

QStringList FirstClass::getClassAmenities()
{
    //list of amenities given in first class
    return
    {
        "-Private suites or fully enclosed seats",
        "-Lie-flat beds with luxurious bedding",
        "-Access to first-class lounges at airports",
        "-Gourmet dining with a personalized menu",
        "-Premium champagne and fine wines",
        "-Dedicated cabin crew for personalized service",
        "-Luxury amenity kits with designer toiletries",
        "-Priority boarding and baggage handling"
    };
}
int FirstClass::seatsAvailable()
{
    //randomly decided seat availability in firstClass
    return QRandomGenerator::global()->bounded(1,14);
}
FirstClass::~FirstClass()
{

}