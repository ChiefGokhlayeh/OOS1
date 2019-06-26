#include "point4.hh"
#include "mydata.hh"

#include <iostream>
#include <sstream>
#include <istream>

using namespace std;

Point::Point(int x, int y) : x(x), y(y)
{
}

Point::Point(const char *c)
{
    stringstream buf(c);
    buf >> *this;
}

Point::Point(const string &str)
{
    stringstream buf(str);
    buf >> *this;
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

void Point::Print() const
{
    Print(true);
}

string Point::ToString() const
{
    stringstream buf;
    buf << "(" << x << ", " << y << ")";
    return buf.str();
}

Point *Point::Clone() const
{
    return new Point(*this);
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

Point &Point::operator=(const MyData &other)
{
    const Point *p = dynamic_cast<Point *>(const_cast<MyData *>(&other));
    x = p->x;
    y = p->y;
    return *this;
}

bool Point::operator==(const MyData &other) const
{
    const Point *p = dynamic_cast<Point *>(const_cast<MyData *>(&other));
    return p != nullptr && p->x == x && p->y == y;
}

bool Point::operator!=(const MyData &other) const
{
    const Point *p = dynamic_cast<Point *>(const_cast<MyData *>(&other));
    return p == nullptr || p->x != x || p->y != y;
}
