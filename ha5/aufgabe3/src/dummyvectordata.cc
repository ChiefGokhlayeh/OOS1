#include "dummyvectordata.hh"

#include <iostream>
#include <ostream>

using namespace std;

DummyVectorData::DummyVectorData()
{
}

MyVectorData *DummyVectorData::Clone() const
{
    return new DummyVectorData();
}

void DummyVectorData::Print() const
{
    cout << *this;
}

std::string DummyVectorData::ToString() const
{
    return "{ /* DummyVectorData*/ }"s;
}

bool DummyVectorData::operator==(const MyVectorData &other) const
{
    return false;
}

bool DummyVectorData::operator!=(const MyVectorData &other) const
{
    return true;
}
