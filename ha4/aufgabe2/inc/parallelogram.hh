#ifndef PARALELLOGRAM_HH_
#define PARALELLOGRAM_HH_

class Paralellogram
{
private:
    double a, b, phi;

public:
    Paralellogram(double a, double b, double phi);

    virtual double GetA() const;
    virtual double GetB() const;
    virtual double GetPhi() const;

    virtual void SetA(double a);
    virtual void SetB(double b);
    virtual void SetPhi(double phi);

    virtual void Print() const;
};

#endif
