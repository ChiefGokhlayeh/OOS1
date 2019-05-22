#include "rectangle.hh"

Rectangle::Rectangle(double a, double b)
    : Paralellogram(a, b, 90)
{
}

double Rectangle::GetA() const
{
    return Paralellogram::GetA();
}

double Rectangle::GetB() const
{
    return Paralellogram::GetB();
}

double Rectangle::GetPhi() const
{
    return Paralellogram::GetPhi();
}

void Rectangle::SetA(double a)
{
    return Paralellogram::SetA(a);
}

void Rectangle::SetB(double b)
{
    return Paralellogram::SetB(b);
}

void Rectangle::Print() const
{
    return Paralellogram::Print();
}
