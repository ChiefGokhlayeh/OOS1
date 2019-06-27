#include <iostream>
#include "circle5.hh"
#include "polygon5.hh"

using namespace std;

bool debugConstructor = true;

int main(void)
{
    cout << "Anzahl der Objekte: " << DrawingObject::GetNumberOfObjects();
    cout << endl;
    Point p1;
    cout << "p1 ObjectId: " << p1.GetId() << " " << p1 << endl;
    Point p2(1, 1);
    cout << "p2 ObjectId: " << p2.GetId() << " " << p2 << endl;
    Circle c1(p1, 3);
    cout << "c1 ObjectId: " << c1.GetId() << " " << c1 << endl;
    Polygon l1(p1);
    cout << "l1 ObjectId: " << l1.GetId() << " " << l1 << endl;
    cout << "Anzahl der Objekte: " << c1.GetNumberOfObjects() << endl;
}
