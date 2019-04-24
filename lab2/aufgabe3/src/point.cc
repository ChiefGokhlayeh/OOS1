#include "point.hh"

#include <iostream>

using namespace std;

Point::Point(int x, int y) : x(x), y(y)
{
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
    cout << "(" << x << ", " << y << ")";
    if (lf)
        cout << endl;
}
