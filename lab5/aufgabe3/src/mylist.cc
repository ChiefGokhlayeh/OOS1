#include "mylist.hh"

#include <cassert>
#include <algorithm>
#include <ostream>
#include <iostream>

using namespace std;

MyList::MyList()
    : first(nullptr), last(nullptr), size(0)
{
}

MyList::MyList(const MyList &other)
    : first(nullptr), last(nullptr), size(0)
{
    MyListElement *cur = other.first;
    while (cur != nullptr)
    {
        PushBack(cur->GetData());
        cur = cur->GetNext();
    }
}

MyList ::~MyList()
{
    delete first;
}

void MyList::PushBack(const MyData &data)
{
    MyListElement *elem = new MyListElement(data);
    if (last == nullptr)
    {
        assert(first == nullptr);
        first = last = elem;
        size++;
    }
    else
    {
        last->SetNext(elem);
        last = elem;
        size++;
    }
}

void MyList::PopBack()
{
    if (last == nullptr)
    {
        /* nothing to do */
        assert(first == nullptr);
    }
    else
    {
        assert(first != nullptr);
        MyListElement *prev = nullptr;
        MyListElement *cur = first;
        while (cur != nullptr && cur != last)
        {
            prev = cur;
            cur = cur->GetNext();
        }
        if (prev == nullptr)
        {
            first = nullptr;
            last = nullptr;
            size = 0;
        }
        else
        {
            prev->SetNext(nullptr);
            last = prev;
            assert(size > 0);
            size--;
        }
        if (cur != nullptr)
            delete cur;
    }
}
void MyList::Clear()
{
    delete first;
    first = last = nullptr;
    size = 0;
}

bool MyList::Empty() const
{
    return size <= 0;
}

int MyList::Size() const
{
    return size;
}

MyData &MyList::Front() const
{
    return first->GetData();
}

MyData &MyList::Back() const
{
    return last->GetData();
}

void MyList::Print() const
{
    cout << *this << endl;
}

MyList &MyList::operator=(const MyList &other)
{
    /* What a mess... this code tries to be exception safe, assuming
     * f.SetNext() won't throw. */
    if (this != &other)
    {
        if (other.Empty())
        {
            first = nullptr;
            last = nullptr;
            size = 0;
        }
        else
        {
            MyListElement f(*other.first);
            MyListElement *l = nullptr;
            MyListElement *cur = f.GetNext();

            int s = 1;
            while (cur != nullptr)
            {
                l = cur;
                cur = cur->GetNext();
                s++;
            }
            MyListElement *fp = new MyListElement(f.GetData(), f.GetNext());
            f.SetNext(nullptr);

            if (first != nullptr)
                delete first;
            first = fp;
            last = l == nullptr ? fp : l;
            size = s;
        }
    }
    return *this;
}

MyList MyList::operator+(const MyList &other)
{
    MyList tmp(*this);
    MyListElement *cur = other.first;
    while (cur != nullptr)
    {
        tmp.PushBack(cur->GetData());
        cur = cur->GetNext();
    }
    return tmp;
}

ostream &operator<<(ostream &os, const MyList &data)
{
    os << "[ ";
    MyListElement *cur = data.first;
    while (cur != nullptr)
    {
        os << *cur << " ";
        cur = cur->GetNext();
    }
    os << "]";
    return os;
}

MyListElement::MyListElement(const MyListElement &other)
    : data(other.GetData().Clone()), next(nullptr)
{
    if (other.next != nullptr)
    {
        next = new MyListElement(*other.next);
    }
}

MyListElement::MyListElement(const MyData &data)
    : data(data.Clone()), next(nullptr)
{
}
MyListElement::MyListElement(const MyData &data, MyListElement *next)
    : data(data.Clone()), next(next)
{
}

MyListElement::~MyListElement()
{
    delete data;
    if (next != nullptr)
        delete next;
}

MyListElement *MyListElement::GetNext() const
{
    return next;
}

void MyListElement::SetNext(MyListElement *next)
{
    this->next = next;
}

MyData &MyListElement::GetData() const
{
    return *data;
}

bool MyListElement::HasNext() const
{
    return data != nullptr;
}

ostream &operator<<(ostream &os, const MyListElement &elem)
{
    os << *elem.data;
    return os;
}
