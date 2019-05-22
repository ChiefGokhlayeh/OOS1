#ifndef RECTANGLE_HH_
#define RECTANGLE_HH_

#include "parallelogram.hh"

class Rectangle : protected Paralellogram
{
public:
    Rectangle(double a, double b);

    double GetA() const override;
    double GetB() const override;
    double GetPhi() const override;

    void SetA(double a) override;
    void SetB(double b) override;

    void Print() const override;
};

#endif
