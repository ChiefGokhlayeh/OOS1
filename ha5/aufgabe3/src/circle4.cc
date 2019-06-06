#include "circle4.hh"

#include <iostream>
#include <sstream>

using namespace std;

Circle::Circle(const Point &c, double r) : centre(c), radius(r)
{
}

Circle::Circle(const char *c)
{
    stringstream buf(c);
    buf >> *this;
}

Circle::Circle(const string &str)
{
    stringstream buf(str);
    buf >> *this;
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

void Circle::Print() const
{
    Print(true);
}

string Circle::ToString() const
{
    stringstream buf;
    buf << "<";
    buf << centre.ToString();
    buf << ", " << radius << ">";
    return buf.str();
}

Circle *Circle::Clone() const
{
    return new Circle(*this);
}

Circle &Circle::operator=(const MyVectorData &other)
{
    const Circle *c = dynamic_cast<Circle *>(const_cast<MyVectorData *>(&other));
    radius = c->radius;
    centre = c->centre;
    return *this;
}

bool Circle::operator==(const MyVectorData &other) const
{
    const Circle *c = dynamic_cast<Circle *>(const_cast<MyVectorData *>(&other));
    return c != nullptr && c->radius == radius && c->centre == centre;
}

bool Circle::operator!=(const MyVectorData &other) const
{
    const Circle *c = dynamic_cast<Circle *>(const_cast<MyVectorData *>(&other));
    return c == nullptr || c->radius != radius || c->centre != centre;
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
