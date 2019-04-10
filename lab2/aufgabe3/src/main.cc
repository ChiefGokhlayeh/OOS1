#include "point.hh"
#include "circle.hh"
#include "polygon.hh"

#include <iostream>

using namespace std;

int main()
{
    Point p;
    Circle c(p);
    cout << "Ausgabe 1:" << endl;
    p.Print();
    c.Print();
    p.SetX(1.1);
    p.SetY(2.2);
    c.SetCentre(p);
    c.SetRadius(3.3);
    cout << "Ausgabe 2:" << endl;
    p.Print(false);
    cout << " == (" << p.GetX() << ", " << p.GetY() << ")"
         << endl;
    c.Print();
    p.Move(1.0, 1.0);
    c.Move(2.0, 2.0);
    cout << "Ausgabe 3:" << endl;
    p.Print();
    c.Print();

    Point p1(1, 1), p2(2, 2), p3(3, 3), p4(4, 4), p5(5, 5);
    Polygon l1;
    Polygon l2(p3);
    cout << "Ausgabe 1:" << endl;
    l1.Print();
    l2.Print();
    l1.AddPoint(p1).AddPoint(p2);
    l2.AddPoint(p4).AddPoint(p5);
    cout << "Ausgabe 2:" << endl;
    l1.Print();
    l2.Print();
    p2.Move(0.5, 0.5);
    cout << "Ausgabe 3:" << endl;
    p2.Print();
    l1.Print();
    l2.Print();
    l1.Append(l2);
    cout << "Ausgabe 4:" << endl;
    l1.Print();
    l2.Print();
    l1.Move(0, 0.5);
    cout << "Ausgabe 5:" << endl;
    l1.Print();
    l2.Print();

    return 0;
}
