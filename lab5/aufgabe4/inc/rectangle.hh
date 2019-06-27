#ifndef RECTANGLE_HH_
#define RECTANGLE_HH_

#include "onedimobject2.hh"
#include "point6.hh"

#include <ostream>
#include <istream>

class Rectangle : public OneDimObject
{
private:
    Point p1, p2;

public:
    Rectangle(const Point &p1 = Point(0, 0), const Point &p2 = Point(1, 1));

    void Print(bool lf = false) const override;
    std::string ToString() const;

    friend std::ostream &operator<<(std::ostream &, const Rectangle &);
    friend std::istream &operator>>(std::istream &, Rectangle &);
};

#endif
