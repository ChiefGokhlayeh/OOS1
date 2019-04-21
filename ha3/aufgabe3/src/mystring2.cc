#include "mystring2.hh"

#include <cstring>
#include <algorithm>
#include <ostream>

using namespace std;

MyString::MyString()
{
    strSize = 0;
    strCapacity = 0;
    strPtr = new char[strCapacity + 1];
    strPtr[strCapacity] = '\0';
    nullChar = '\0';
}

MyString::MyString(const char *cstr)
{
    strSize = strlen(cstr);
    strCapacity = strSize;
    strPtr = new char[strCapacity + 1];
    strncpy(strPtr, cstr, strCapacity + 1);
    nullChar = '\0';
}

MyString::MyString(const MyString &mystr)
{
    strSize = mystr.strSize;
    strCapacity = mystr.strCapacity;
    strPtr = new char[strCapacity + 1];
    strncpy(strPtr, mystr.strPtr, strCapacity + 1);
    nullChar = '\0';
}

MyString::~MyString()
{
    if (strPtr != nullptr)
    {
        delete[] strPtr;
        strPtr = nullptr;
    }
    strSize = 0;
    strCapacity = 0;
}

void MyString::Reserve(unsigned int c)
{
    if (c > strCapacity)
    {
        char *newStrPtr = new char[c + 1];
        if (strPtr != nullptr)
        {
            strncpy(newStrPtr, strPtr, strSize + 1);
            delete[] strPtr;
        }
        strPtr = newStrPtr;
        strCapacity = c;
    }
}

MyString &MyString::Append(const MyString &mystr)
{
    if (strCapacity < strSize + mystr.strSize)
    {
        Reserve(strSize + mystr.strSize);
    }
    strncpy(strPtr + strSize, mystr.strPtr, mystr.strSize + 1);

    return *this;
}

MyString &MyString::Assign(const MyString &mystr)
{
    if (strPtr != nullptr)
    {
        delete[] strPtr;
    }
    strPtr = new char[mystr.strCapacity + 1];
    strncpy(strPtr, mystr.strPtr, mystr.strCapacity + 1);
    strSize = mystr.strSize;
    strCapacity = mystr.strCapacity;
    return *this;
}

const char *MyString::C_str() const
{
    return strPtr;
}

unsigned int MyString::Size() const
{
    return strSize;
}

unsigned int MyString::Capacity() const
{
    return strCapacity;
}

bool MyString::Empty() const
{
    return strSize == 0;
}

char &MyString::At(unsigned int i)
{
    if (i >= strSize)
    {
        /* This is stupid. A API caller might change the value of nullChar, but
        due to spec we HAVE to return a reference to a null-char on
        out-of-bounds. */
        nullChar = '\0';
        return nullChar;
    }
    else
    {
        return strPtr[i];
    }
}

void MyString::Clear()
{
    strSize = 0;
    if (strPtr != nullptr)
    {
        strPtr[0] = '\0';
    }
}

MyString operator+(const MyString& left, const MyString &right)
{
    MyString s(left);
    s.Append(right);
    return s;
}

MyString &MyString::operator+=(const MyString &other)
{
    Append(other);
    return *this;
}

MyString &MyString::operator=(const MyString &other)
{
    Assign(other);
    return *this;
}

bool MyString::operator==(const MyString &other) const
{
    if (this == &other)
    {
        return true;
    }
    else if (strSize == other.strSize && strcmp(strPtr, other.strPtr) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

char &MyString::operator[](unsigned int i)
{
    return At(i);
}

ostream &operator<<(ostream &os, const MyString& myStr)
{
    os << myStr.C_str();
    return os;
}
