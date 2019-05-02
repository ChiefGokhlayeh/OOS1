#include "circle.hh"

#include <iostream>

using namespace std;

Circle::Circle(const Point &c, double r) : centre(c), radius(r)
{
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
    cout << "<";
    centre.Print(false);
    cout << ", " << radius << ">";
    if (lf)
        cout << endl;
}
