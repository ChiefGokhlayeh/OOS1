#ifndef CIRCLE_HH_
#define CIRCLE_HH_

#include "point4.hh"

#include <string>
#include <istream>
#include <ostream>

class Circle : public MyData
{
public:
    Circle(const Point &c = Point(), double r = 1.0);
    Circle(const char *c);
    Circle(const std::string &str);

    double GetRadius() const;
    const Point &GetCentre() const;
    void SetRadius(double radius);
    void SetCentre(const Point &centre);

    void Move(double dx, double dy);
    void Print(bool lf = true) const;
    virtual std::string ToString() const override;

    virtual Circle *Clone() const override;
    virtual void Print() const override;

    virtual Circle &operator=(const MyData &other) override;
    virtual bool operator==(const MyData &other) const override;
    virtual bool operator!=(const MyData &other) const override;

    friend std::istream &operator>>(std::istream &is, Circle &c);
    friend std::ostream &operator<<(std::ostream &os, const Circle &c);

private:
    Point centre;
    double radius;
};

#endif
