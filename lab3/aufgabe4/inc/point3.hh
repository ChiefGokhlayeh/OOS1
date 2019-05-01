#ifndef POINT_HH_
#define POINT_HH_

#include <string>
#include <istream>
#include <ostream>

class Point
{
  public:
    Point(int x = 0, int y = 0);
    Point(const char *c);
    Point(const std::string &str);

    double GetX() const;
    double GetY() const;
    void SetX(double x);
    void SetY(double y);

    void Move(double dx, double dy);
    void Print(bool lf = true) const;
    std::string ToString() const;

    friend std::istream &operator>>(std::istream &is, Point &p);
    friend std::ostream &operator<<(std::ostream &os, const Point &p);

  private:
    double x, y;
};

#endif
