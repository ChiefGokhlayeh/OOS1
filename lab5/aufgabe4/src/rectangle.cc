#include "rectangle.hh"

#include <string>
#include <istream>
#include <ostream>
#include <iostream>
#include <sstream>

using namespace std;

Rectangle::Rectangle(const Point &p1, const Point &p2)
    : p1(p1), p2(p2)
{
}

void Rectangle::Print(bool lf) const
{
    cout << ToString();
    if (lf)
        cout << endl;
}

string Rectangle::ToString() const
{
    stringstream buf;
    buf << "[" << p1 << ", " << p2 << "]";
    return buf.str();
}

ostream &operator<<(ostream &os, const Rectangle &p)
{
    os << p.ToString();
    return os;
}

istream &operator>>(istream &is, Rectangle &p)
{
    /* [(9.1, 12.1), (1.81, 3.1)] */
    bool started = false;
    bool done = false;
    while (!is.eof() && !done)
    {
        switch (is.get())
        {
        case '[':
            if (!started)
            {
                is >> p.p1;
            }
            started = true;
            break;
        case ',':
            if (started)
            {
                is >> p.p2;
            }
            break;
        case ']':
            done = true;
            break;
        default:
            /* ignore */
            break;
        }
    }
    return is;
}
