#include "BookingClass.h"
#include <QRandomGenerator>
BookingClass::BookingClass()
{

}
float BookingClass::randomPrice()
{
    //randomly assigns price 
    return QRandomGenerator::global()->bounded(50) + 200;
}
