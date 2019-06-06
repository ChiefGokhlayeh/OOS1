#include "myvector.hh"
#include "myvectordata.hh"
#include "dummyvectordata.hh"

#include <algorithm>
#include <iostream>
#include <ostream>

using namespace std;

static void CopyData(MyVectorData *dest[], const MyVectorData *const src[], size_t elemCount)
{
    for (size_t i = 0; i < elemCount; ++i)
    {
        dest[i] = src[i]->Clone();
    }
}

MyVector::MyVector()
    : nullVec()
{
    dataSize = 0;
    dataCapacity = 0;
    dataPtr = new MyVectorData *[dataCapacity];
}

MyVector::MyVector(const MyVector &myvec)
    : nullVec()
{
    dataSize = myvec.dataSize;
    dataCapacity = myvec.dataCapacity;
    dataPtr = new MyVectorData *[dataCapacity];

    CopyData(dataPtr, myvec.dataPtr, dataSize);
}

MyVector::~MyVector()
{
    Clear();
    if (dataPtr != nullptr)
    {
        delete[] dataPtr;
        dataPtr = nullptr;
    }
    dataCapacity = 0;
}

void MyVector::Reserve(unsigned int c)
{
    if (c > dataCapacity)
    {
        MyVectorData **newDataPtr = new MyVectorData *[c];
        if (dataPtr != nullptr)
        {
            CopyData(newDataPtr, dataPtr, dataSize);
            delete[] dataPtr;
        }
        dataPtr = newDataPtr;
        dataCapacity = c;
    }
}

MyVector &MyVector::Append(const MyVector &myvec)
{
    if (dataCapacity < dataSize + myvec.dataSize)
    {
        Reserve(dataSize + myvec.dataSize);
    }

    CopyData(dataPtr + dataSize, myvec.dataPtr, myvec.dataSize);

    return *this;
}

MyVector &MyVector::Assign(const MyVector &myvec)
{
    if (dataPtr != nullptr)
    {
        delete[] dataPtr;
    }
    dataPtr = new MyVectorData *[myvec.dataCapacity];
    CopyData(dataPtr, myvec.dataPtr, myvec.dataCapacity);
    dataSize = myvec.dataSize;
    dataCapacity = myvec.dataCapacity;
    return *this;
}

unsigned int MyVector::Size() const
{
    return dataSize;
}

unsigned int MyVector::Capacity() const
{
    return dataCapacity;
}

bool MyVector::Empty() const
{
    return dataSize == 0;
}

MyVectorData &MyVector::At(unsigned int i)
{
    if (i >= dataSize)
    {
        /* This is stupid. A API caller might change the value of nullVec, but
        due to spec we HAVE to return a reference to an empty DummyVectorData on
        out-of-bounds. */
        return nullVec;
    }
    else
    {
        return *dataPtr[i];
    }
}

void MyVector::PushBack(const MyVectorData &data)
{
    MyVectorData *clone = data.Clone();

    if (dataSize == dataCapacity)
    {
        Reserve((dataCapacity + 1) * 2);
    }

    dataPtr[dataSize] = clone;

    dataSize++;
}

void MyVector::Print(bool lf) const
{
    cout << *this;
    if (lf)
        cout << endl;
}

void MyVector::Clear()
{
    if (dataPtr != nullptr)
    {
        for (size_t i = 0; i < dataSize; i++)
        {
            delete dataPtr[i];
            dataPtr[i] = nullptr;
        }
    }
    dataSize = 0;
}

MyVector operator+(const MyVector &left, const MyVector &right)
{
    MyVector s(left);
    s.Append(right);
    return s;
}

MyVector &MyVector::operator+=(const MyVector &other)
{
    Append(other);
    return *this;
}

MyVector &MyVector::operator=(const MyVector &other)
{
    Assign(other);
    return *this;
}

bool MyVector::operator==(const MyVector &other) const
{
    if (this == &other)
    {
        return true;
    }
    else if (dataSize == other.dataSize)
    {
        for (size_t i = 0; i < dataSize; ++i)
        {
            if ((*dataPtr[i]) != (*other.dataPtr[i]))
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

MyVectorData &MyVector::operator[](unsigned int i)
{
    return At(i);
}

ostream &operator<<(ostream &os, const MyVector &myvec)
{
    os << "[ ";
    for (size_t i = 0; i < myvec.dataSize; ++i)
    {
        os << *myvec.dataPtr[i];
        if (i < (myvec.dataSize - 1))
        {
            os << ", ";
        }
    }
    os << " ]";
    return os;
}
