#include "Date.h"

Date::Date()
{

}

Date :: Date(int d, int m, int y)
{
    this->day = d;
    this->month = m;
    this->year = y;
}

Date::~Date()
{

}

void Date :: setDay(int d)
{
    this->day = d;
}


void Date :: setMonth(int m)
{
    this->month = m;
}

void Date :: setYear(int y)
{
   this->year = y;
}

int Date :: getDay() const
{
    return this->day;
}

int Date :: getMonth() const
{
   return this->month;
}

int Date :: getYear() const
{
   return this->year;
}
