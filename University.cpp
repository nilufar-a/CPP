#include "University.h"


University :: University()
{

}


University ::  University(string n, string d, Date sD, Date eD, int p, int c,int numHw, int numMid) : Task(n, d, sD, eD, p, c)
{
    this->numHw = numHw;
    this->numMid = numMid;
}


University::~University()
{

}


void University :: setNumHw(int numHw)
{
    this->numHw = numHw;
}


void University :: setNumMid(int numMid)
{
    this->numMid = numMid;
}


int University :: getNumHw() const
{
    return this->numHw;
}


int University :: getNumMid() const
{
    return this->numMid;
}
