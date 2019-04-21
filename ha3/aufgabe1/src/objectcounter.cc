#include "objectcounter.hh"

#include <algorithm>

unsigned int ObjectCounter::number = 0;
unsigned int ObjectCounter::maxId = 0;

ObjectCounter::ObjectCounter()
    : id(maxId + 1)
{
    maxId = id;
    number++;
}

ObjectCounter::~ObjectCounter()
{
    number--;
}

unsigned int ObjectCounter::GetId() const
{
    return id;
}

unsigned int ObjectCounter::GetMaxId()
{
    return maxId;
}

unsigned int ObjectCounter::GetNumberOfObjects()
{
    return number;
}
