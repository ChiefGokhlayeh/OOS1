#ifndef MYVECTOR_HH_
#define MYVECTOR_HH_

#include "myvectordata.hh"
#include "dummyvectordata.hh"

#include <ostream>

class MyVector
{
private:
    MyVectorData **dataPtr;
    unsigned int dataSize;
    unsigned int dataCapacity;
    DummyVectorData nullVec;

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
    MyVectorData &At(unsigned int i);

    void PushBack(const MyVectorData &data);
    void Print(bool lf = true) const;

    void Clear();

    friend MyVector operator+(const MyVector &left, const MyVector &right);
    MyVector &operator+=(const MyVector &other);
    MyVector &operator=(const MyVector &other);
    bool operator==(const MyVector &other) const;
    MyVectorData &operator[](unsigned int i);
    friend std::ostream &operator<<(std::ostream &os, const MyVector &myvec);
};

#endif
