#ifndef MYLIST_HH_
#define MYLIST_HH_

#include "mydata.hh"

#include <ostream>

class MyListElement
{
private:
    MyListElement *next;
    MyData *const data;

public:
    MyListElement(const MyListElement &);
    MyListElement(const MyData &);
    MyListElement(const MyData &, MyListElement *);
    ~MyListElement();

    MyListElement *GetNext() const;
    void SetNext(MyListElement *);
    bool HasNext() const;

    MyData &GetData() const;

    friend std::ostream &operator<<(std::ostream &, const MyListElement &);
};

class MyList
{
private:
    MyListElement *first;
    MyListElement *last;

    int size;

public:
    MyList();
    MyList(const MyList &);
    ~MyList();

    void PushBack(const MyData &);
    void PopBack();

    MyData &Front() const;
    MyData &Back() const;

    void Clear();

    bool Empty() const;
    int Size() const;

    void Print() const;

    MyList &operator=(const MyList &);
    MyList operator+(const MyList &);

    friend std::ostream &operator<<(std::ostream &, const MyList &);
};

#endif
