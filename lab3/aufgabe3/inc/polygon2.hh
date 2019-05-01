#ifndef POLYGON_HH_
#define POLYGON_HH_

#include "point2.hh"

#include <string>
#include <istream>

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

class Polygon
{
  public:
    Polygon();
    Polygon(const Point &p);
    Polygon(const char *c);
    Polygon(const std::string &c);
    ~Polygon();

    void Move(double dx, double dy);
    void Print(bool lf = true) const;
    std::string ToString() const;
    Polygon &AddPoint(const Point &point);
    Polygon &Append(const Polygon &polygon);

    friend std::istream &operator>>(std::istream &is, Polygon &poly);

  private:
    PolygonPoint *root;
};

#endif
