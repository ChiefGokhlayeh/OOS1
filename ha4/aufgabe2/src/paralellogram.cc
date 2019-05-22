#include "parallelogram.hh"

#include <iostream>

using namespace std;

Paralellogram::Paralellogram(double a, double b, double phi)
    : a(a), b(b), phi(phi)
{
}

double Paralellogram::GetA() const
{
    return a;
}
double Paralellogram::GetB() const
{
    return b;
}
double Paralellogram::GetPhi() const
{
    return phi;
}

void Paralellogram::SetA(double a)
{
    this->a = a;
}
void Paralellogram::SetB(double b)
{
    this->b = b;
}
void Paralellogram::SetPhi(double phi)
{
    this->phi = phi;
}

void Paralellogram::Print() const
{
    cout << "Seite a = " << a << "    Seite b = " << b << "    Phi = " << phi << endl;
}
