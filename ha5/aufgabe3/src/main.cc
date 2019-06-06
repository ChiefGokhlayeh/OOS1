#include "myvector.hh"
#include "circle4.hh"

#include <iostream>

using namespace std;

int main()
{
    MyVector v1;
    Point p1(1, 1);
    Point p2(2, 2);
    Point p3(3, 3);
    Point p4(4, 4);
    v1.PushBack(p1);
    v1.PushBack(p2);
    v1.PushBack(p3);
    v1.At(1).Print();
    v1.At(2).Print();
    v1.At(1) = v1.At(2);
    v1.Print();
    MyVector v2(v1);
    v2.Print();
    dynamic_cast<Point &>(v1.At(2)).Move(10, 10);
    v1.Print();
    v2.Print();
    cout << "Groesse von v1: " << v1.Size();
    cout << "  Kapazitaet von v1: " << v1.Capacity() << endl;
    if (!v1.Empty())
    {
        v1.Clear();
    }
    cout << "Groesse von v1: " << v1.Size();
    cout << "  Kapazitaet von v1: " << v1.Capacity() << endl;
    v1.Print();
    v2.Print();
    cout << "Groesse von v2: " << v2.Size();
    cout << "  Kapazitaet von v2: " << v2.Capacity() << endl;
    v2.PushBack(p1);
    cout << "Groesse von v2: " << v2.Size();
    cout << "  Kapazitaet von v2: " << v2.Capacity() << endl;
    v2.Print();
    v1.PushBack(p1);
    v2.Append(v1);
    v1.Print();
    v2.Print();
    cout << "Kreise: " << endl;
    MyVector v3;
    Circle c1(p1, 1);
    Circle c2(p2, 2);
    v3.PushBack(c1);
    v3.PushBack(c2);
    v3.Print();
    return 0;
}
