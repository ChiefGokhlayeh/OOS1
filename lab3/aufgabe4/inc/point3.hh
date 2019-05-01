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

    friend Point operator-(Point a);
    friend Point operator+(Point a, const Point &b);
    friend Point operator+(Point a, const double &b);
    friend Point operator+(const double &a, const Point &b);
    Point &operator+=(const Point &a);
    Point &operator+=(const double &a);
    friend Point operator-(const Point &a, const Point &b);
    friend Point operator-(const Point &a, const double &b);
    friend Point operator-(const double &a, const Point &b);
    Point &operator-=(const Point &a);
    Point &operator-=(const double &a);

    Point &operator++();
    Point operator++(int);
    Point &operator--();
    Point operator--(int);

  private:
    double x, y;
};

#endif
