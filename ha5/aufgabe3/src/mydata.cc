#include "mydata.hh"

#include <ostream>
#include <string>

using namespace std;

MyData::~MyData()
{
}

string MyData::ToString() const
{
    return "{ /* MyData */ }"s;
}

MyData &MyData::operator=(const MyData &other)
{
    return *this;
}

ostream &operator<<(ostream &os, const MyData &data)
{
    os << data.ToString();
    return os;
}
