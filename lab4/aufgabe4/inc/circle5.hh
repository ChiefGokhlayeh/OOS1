#ifndef CIRCLE_HH_
#define CIRCLE_HH_

#include "point5.hh"
#include "onedimobject.hh"

#include <string>
#include <istream>
#include <ostream>

class Circle : public OneDimObject
{
public:
    Circle(const Point &c = Point(), double r = 1.0);
    Circle(const char *c);
    Circle(const std::string &str);
    virtual ~Circle();

    double GetRadius() const;
    const Point &GetCentre() const;
    void SetRadius(double radius);
    void SetCentre(const Point &centre);

    void Move(double dx, double dy);
    void Print(bool lf = true) const;
    std::string ToString() const;

    friend std::istream &operator>>(std::istream &is, Circle &c);
    friend std::ostream &operator<<(std::ostream &os, const Circle &c);

    Circle &operator=(Circle c);

private:
    Point centre;
    double radius;
};

#endif
