#ifndef POLYGON_HH_
#define POLYGON_HH_

#include "point.hh"

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

private:
  Point point;
  PolygonPoint *next;
};

class Polygon
{
public:
  Polygon();
  Polygon(const Point &p);
  ~Polygon();

  void Move(double dx, double dy);
  void Print(bool lf = true) const;
  Polygon &AddPoint(Point &point);
  Polygon &Append(const Polygon &polygon);

private:
  PolygonPoint *root;
};

#endif
