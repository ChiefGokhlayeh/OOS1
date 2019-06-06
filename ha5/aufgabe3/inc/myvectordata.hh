#ifndef MYVECTORDATA_HH_
#define MYVECTORDATA_HH_

#include <ostream>

class MyVectorData
{
public:
    virtual ~MyVectorData();

    virtual std::string ToString() const;

    virtual MyVectorData *Clone() const = 0;
    virtual void Print() const = 0;

    virtual MyVectorData &operator=(const MyVectorData &other);
    virtual bool operator==(const MyVectorData &other) const = 0;
    virtual bool operator!=(const MyVectorData &other) const = 0;
    friend std::ostream &operator<<(std::ostream &os, const MyVectorData &data);
};

#endif
