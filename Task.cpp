#include "Task.h"


Task::Task()
{

}


Task :: Task(string n, string d, Date sD, Date eD, int p, int c) {
    this->name = n;
    this->description = d;
    this->startDate = sD;
    this->endDate = eD;
    this->priority = p;
    this->category = c;
}


Task::~Task()
{

}


void Task :: setName(string name)
{
  this->name = name;
}


void Task :: setDescription(string description)
{
    this->description = description;
}


void Task :: setStartDate(Date startDate)
{
    this->startDate = startDate;
}


void Task :: setEndDate(Date endDate)
{
   this->endDate = endDate;
}


void Task :: setPriority(int priority)
{
    this->priority = priority;
}


void Task :: setCategory(int category)
{
    this->category = category;
}


string Task :: getName() const
{
    return this->name;
}


string Task :: getDescription() const
{
    return this->description;
}

Date Task :: getStartDate() const
{
    return this->startDate;
}


Date Task :: getEndDate() const
{
    return this->endDate;
}


int Task :: getPriority() const
{
    return this->priority;
}


int Task :: getCategory() const
{
  return this->category;
}


void Task :: setData1(int data1)
{
    this->data1 = data1;
}


void Task :: setData2(int data2)
{
    this->data2 = data2;
}


int Task :: getData1()
{
    return this->data1;
}


int Task :: getData2()
{
    return this->data2;
}
