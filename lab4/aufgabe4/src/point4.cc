#include "point4.hh"

#include <iostream>
#include <sstream>
#include <istream>

using namespace std;

extern bool debugConstructor;

Point::Point(int x, int y)
    : DrawingObject(), x(x), y(y)
{
    if (debugConstructor)
    {
        cout << "Konstruktor der Klasse Point, Object: " << GetId() << endl;
    }
}

Point::Point(const char *c)
    : DrawingObject()
{
    if (debugConstructor)
    {
        cout << "Konstruktor der Klasse Point, Object: " << GetId() << endl;
    }
    stringstream buf(c);
    buf >> *this;
}

Point::Point(const string &str)
    : DrawingObject()
{
    if (debugConstructor)
    {
        cout << "Konstruktor der Klasse Point, Object: " << GetId() << endl;
    }
    stringstream buf(str);
    buf >> *this;
}
Point::Point(const Point &c)
    : DrawingObject()
{
    if (debugConstructor)
    {
        cout << "Konstruktor der Klasse Point, Object: " << GetId() << endl;
    }
    x = c.x;
    y = c.y;
}

Point::~Point()
{
    if (debugConstructor)
    {
        cout << "Destruktor der Klasse Point, Object: " << GetId() << endl;
    }
}

double Point::GetX() const
{
    return x;
}

double Point::GetY() const
{
    return y;
}

void Point::SetX(double x)
{
    this->x = x;
}

void Point::SetY(double y)
{
    this->y = y;
}

void Point::Move(double dx, double dy)
{
    x += dx;
    y += dy;
}

void Point::Print(bool lf) const
{
    cout << ToString();
    if (lf)
        cout << endl;
}

string Point::ToString() const
{
    stringstream buf;
    buf << "(" << x << ", " << y << ")";
    return buf.str();
}

istream &operator>>(istream &is, Point &p)
{
    /* (9.1, 12.1) */
    bool started = false;
    bool done = false;
    while (!is.eof() && !done)
    {
        switch (is.get())
        {
        case '(':
            if (!started)
            {
                is >> p.x;
            }
            started = true;
            break;
        case ',':
            if (started)
            {
                is >> p.y;
            }
            break;
        case ')':
            done = true;
            break;
        default:
            /* ignore */
            break;
        }
    }
    return is;
}

ostream &operator<<(ostream &os, const Point &p)
{
    os << p.ToString();
    return os;
}

Point operator-(Point a)
{
    a.SetX(-a.GetX());
    a.SetY(-a.GetY());
    return a;
}

Point operator+(Point a, const Point &b)
{
    a.Move(b.GetX(), b.GetY());
    return a;
}

Point operator+(Point a, const double &b)
{
    a.Move(b, b);
    return a;
}

Point operator+(const double &a, const Point &b)
{
    return b + a;
}

Point &Point::operator+=(const Point &a)
{
    Move(a.GetX(), a.GetY());
    return *this;
}

Point &Point::operator+=(const double &a)
{
    Move(a, a);
    return *this;
}

Point operator-(const Point &a, const Point &b)
{
    return a + (-b);
}

Point operator-(const Point &a, const double &b)
{
    return a + (-b);
}

Point operator-(const double &a, const Point &b)
{
    return b - a;
}

Point &Point::operator-=(const Point &a)
{
    Move(-a.GetX(), -a.GetY());
    return *this;
}

Point &Point::operator-=(const double &a)
{
    Move(-a, -a);
    return *this;
}

Point &Point::operator++()
{
    Move(1, 1);
    return *this;
}

Point Point::operator++(int)
{
    Point tmp(*this);
    operator++();
    return tmp;
}

Point &Point::operator--()
{
    Move(-1, -1);
    return *this;
}

Point Point::operator--(int)
{
    Point tmp(*this);
    operator--();
    return tmp;
}

Point &Point::operator=(Point p)
{
    swap(x, p.x);
    swap(y, p.y);
    return *this;
}
