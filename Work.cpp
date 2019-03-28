#include "Work.h"

Work::Work()
{

}


Work::Work(string n, string d, Date sD, Date eD, int p, int c, int hours):Task(n, d, sD, eD, p, c)
{
    this->hours = hours;
}


Work::~Work()
{

}


void Work :: setHours(int hours)
{
    this->hours = hours;
}


int Work :: getHours() const
{
    return this->hours;
}
