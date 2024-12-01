#include "BusinessClass.h"
#include <QStringList>
#include <QRandomGenerator>
BusinessClass::BusinessClass()
{

}

QStringList BusinessClass::getClassAmenities()
{    //list of amenities given in business class
    return QStringList
    {
        "-Spacious seats with enhanced recline and legroom",
        "-Lie-flat or angled-flat seats on long-haul flights",
        "-Access to premium lounges at airports",
        "-Multi-course gourmet meals with fine dining options",
        "-Complimentary wines, beers, and specialty drinks",
        "-High-quality noise-canceling headphones",
        "-Luxury amenity kits with essential toiletries",
        "-Priority boarding and check-in"
    };
}
int BusinessClass::seatsAvailable()
{
    //randomly decided seat availability in businessClass
    return QRandomGenerator::global()->bounded(1,32);
}
BusinessClass::~BusinessClass(){

}