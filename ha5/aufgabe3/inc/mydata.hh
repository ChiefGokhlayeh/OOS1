#ifndef MYDATA_HH_
#define MYDATA_HH_

#include <ostream>

class MyData
{
public:
    virtual ~MyData();

    virtual std::string ToString() const;

    virtual MyData *Clone() const = 0;
    virtual void Print() const = 0;

    virtual MyData &operator=(const MyData &other);
    virtual bool operator==(const MyData &other) const = 0;
    virtual bool operator!=(const MyData &other) const = 0;
    friend std::ostream &operator<<(std::ostream &os, const MyData &data);
};

#endif
