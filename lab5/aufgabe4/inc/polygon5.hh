#ifndef POLYGON_HH_
#define POLYGON_HH_

#include "point5.hh"
#include "onedimobject2.hh"

#include <string>
#include <istream>
#include <ostream>

class PolygonPoint
{
public:
    PolygonPoint(const Point &p, PolygonPoint *next = nullptr);
    PolygonPoint(const PolygonPoint &orig);
    ~PolygonPoint();

    const Point &GetPoint() const;
    PolygonPoint *GetNext() const;
    void SetNext(PolygonPoint *next);
    bool HasNext() const;

    void Move(double dx, double dy);
    void Print(bool lf = true) const;
    std::string ToString() const;

private:
    Point point;
    PolygonPoint *next;
};

class Polygon : public OneDimObject
{
public:
    Polygon();
    Polygon(const Point &p);
    Polygon(const char *c);
    Polygon(const std::string &c);
    virtual ~Polygon() override;

    void Move(double dx, double dy);
    void Print(bool lf = true) const override;
    std::string ToString() const;
    Polygon &AddPoint(const Point &point);
    Polygon &Append(const Polygon &polygon);

    friend std::istream &operator>>(std::istream &is, Polygon &poly);
    friend std::ostream &operator<<(std::ostream &os, const Polygon &poly);

    Polygon &operator+(const Point &p);
    Polygon &operator+(const Polygon &b);

private:
    PolygonPoint *root;
};

#endif
