#include "point2.hh"

#include <iostream>
#include <sstream>
#include <istream>

using namespace std;

Point::Point(int x, int y) : x(x), y(y)
{
}

Point::Point(const char* c)
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
