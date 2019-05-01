#ifndef POINT_HH_
#define POINT_HH_

#include <string>
#include <istream>

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

  private:
    double x, y;
};

#endif
