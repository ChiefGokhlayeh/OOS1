#ifndef DUMMYVECTORDATA_HH_
#define DUMMYVECTORDATA_HH_

#include "myvectordata.hh"

#include <ostream>
#include <string>

class DummyVectorData final : public MyVectorData
{
public:
    DummyVectorData();

    std::string ToString() const override;

    MyVectorData *Clone() const override;
    void Print() const override;

    bool operator==(const MyVectorData &other) const override;
    bool operator!=(const MyVectorData &other) const override;
};

#endif
