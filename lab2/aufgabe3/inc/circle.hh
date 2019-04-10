#ifndef CIRCLE_HH_
#define CIRCLE_HH_

#include "point.hh"

class Circle
{
  public:
    Circle(const Point &c = Point(), double r = 1.0);

    double GetRadius() const;
    const Point &GetCentre() const;
    void SetRadius(double radius);
    void SetCentre(const Point &centre);

    void Move(double dx, double dy);
    void Print(bool lf = true);

  private:
    Point centre;
    double radius;
};

#endif
