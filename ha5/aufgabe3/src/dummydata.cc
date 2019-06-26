#include "dummydata.hh"

#include <iostream>
#include <ostream>

using namespace std;

DummyData::DummyData()
{
}

MyData *DummyData::Clone() const
{
    return new DummyData();
}

void DummyData::Print() const
{
    cout << *this;
}

std::string DummyData::ToString() const
{
    return "{ /* DummyData*/ }"s;
}

bool DummyData::operator==(const MyData &other) const
{
    return false;
}

bool DummyData::operator!=(const MyData &other) const
{
    return true;
}
