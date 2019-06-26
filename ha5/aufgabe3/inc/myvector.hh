#ifndef MYVECTOR_HH_
#define MYVECTOR_HH_

#include "mydata.hh"
#include "dummydata.hh"

#include <ostream>

class MyVector
{
private:
    MyData **dataPtr;
    unsigned int dataSize;
    unsigned int dataCapacity;
    DummyData nullVec;

public:
    MyVector();
    MyVector(const MyVector &myvec);
    ~MyVector();

    void Reserve(unsigned int c);
    MyVector &Append(const MyVector &myvec);
    MyVector &Assign(const MyVector &myvec);

    unsigned int Size() const;
    unsigned int Capacity() const;
    bool Empty() const;
    MyData &At(unsigned int i);

    void PushBack(const MyData &data);
    void Print(bool lf = true) const;

    void Clear();

    friend MyVector operator+(const MyVector &left, const MyVector &right);
    MyVector &operator+=(const MyVector &other);
    MyVector &operator=(const MyVector &other);
    bool operator==(const MyVector &other) const;
    MyData &operator[](unsigned int i);
    friend std::ostream &operator<<(std::ostream &os, const MyVector &myvec);
};

#endif
