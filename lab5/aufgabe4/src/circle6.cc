#include "circle6.hh"

#include <iostream>
#include <sstream>

using namespace std;

extern bool debugConstructor;

Circle::Circle(const Point &c, double r)
    : OneDimObject(), centre(c), radius(r)
{
    if (debugConstructor)
    {
        cout << "Konstrutor der Klasse Circle, Object: " << GetId() << endl;
    }
}

Circle::Circle(const char *c)
{
    if (debugConstructor)
    {
        cout << "Konstrutor der Klasse Circle, Object: " << GetId() << endl;
    }
    stringstream buf(c);
    buf >> *this;
}

Circle::Circle(const string &str)
{
    if (debugConstructor)
    {
        cout << "Konstrutor der Klasse Circle, Object: " << GetId() << endl;
    }
    stringstream buf(str);
    buf >> *this;
}

Circle::~Circle()
{
    if (debugConstructor)
    {
        cout << "Destruktor der Klasse Circle, Object: " << GetId() << endl;
    }
}

double Circle::GetRadius() const
{
    return radius;
}

const Point &Circle::GetCentre() const
{
    return centre;
}

void Circle::SetRadius(double radius)
{
    this->radius = radius;
}

void Circle::SetCentre(const Point &centre)
{
    this->centre = centre;
}

void Circle::Move(double dx, double dy)
{
    centre.Move(dx, dy);
}

void Circle::Print(bool lf) const
{
    cout << ToString();
    if (lf)
        cout << endl;
}

string Circle::ToString() const
{
    stringstream buf;
    buf << "<";
    buf << centre.ToString();
    buf << ", " << radius << ">";
    return buf.str();
}

istream &operator>>(istream &is, Circle &c)
{
    /* <(9.1, 12.1), 1.2> */
    bool started = false;
    bool done = false;
    while (!is.eof() && !done)
    {
        switch (is.get())
        {
        case '<':
            if (!started)
            {
                is >> c.centre;
            }
            started = true;
            break;
        case ',':
            if (started)
            {
                is >> c.radius;
            }
            break;
        case '>':
            done = true;
            break;
        default:
            /* ignore */
            break;
        }
    }
    return is;
}

ostream &operator<<(ostream &os, const Circle &c)
{
    os << c.ToString();
    return os;
}

Circle &Circle::operator=(Circle c)
{
    swap(radius, c.radius);
    swap(centre, c.centre);
    return *this;
}
