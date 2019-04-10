#ifndef POINT_HH_
#define POINT_HH_

class Point
{
public:
  Point(int x = 0, int y = 0);

  double GetX() const;
  double GetY() const;
  void SetX(double x);
  void SetY(double y);

  void Move(double dx, double dy);
  void Print(bool lf = true);

private:
  double x, y;
};

#endif
