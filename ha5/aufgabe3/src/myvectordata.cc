#include "myvectordata.hh"

#include <ostream>
#include <string>

using namespace std;

MyVectorData::~MyVectorData()
{
}

string MyVectorData::ToString() const
{
    return "{ /* MyVectorData */ }"s;
}

MyVectorData &MyVectorData::operator=(const MyVectorData &other)
{
    return *this;
}

ostream &operator<<(ostream &os, const MyVectorData &data)
{
    os << data.ToString();
    return os;
}
