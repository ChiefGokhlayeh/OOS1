#ifndef POINT_HH_
#define POINT_HH_

#include "mydata.hh"

#include <string>
#include <istream>
#include <ostream>

class Point : public MyData
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
    virtual std::string ToString() const override;

    virtual Point *Clone() const override;
    virtual void Print() const override;

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

    virtual Point &operator=(const MyData &other) override;
    virtual bool operator==(const MyData &other) const override;
    virtual bool operator!=(const MyData &other) const override;

private:
    double x, y;
};

#endif
