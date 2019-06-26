#ifndef DUMMYDATA_HH_
#define DUMMYDATA_HH_

#include "mydata.hh"

#include <ostream>
#include <string>

class DummyData final : public MyData
{
public:
    DummyData();

    std::string ToString() const override;

    MyData *Clone() const override;
    void Print() const override;

    bool operator==(const MyData &other) const override;
    bool operator!=(const MyData &other) const override;
};

#endif
