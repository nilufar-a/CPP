#include "Shopping.h"



Shopping::Shopping()
{

}



Shopping::~Shopping()
{

}



Shopping ::  Shopping(string n, string d, Date sD, Date eD, int p, int c,  int price, int quant) : Task(n, d, sD, eD, p, c)
{
    this->price = price;
    this->quant=quant;
}


void Shopping :: setPrice(int price)
{
    this->price = price;
}

void Shopping :: setQuant(int quant)
{
    this->quant = quant;
}

int Shopping :: getPrice() const
{
    return this->price;
}

int Shopping :: getQuant() const
{
    return this->quant;
}
