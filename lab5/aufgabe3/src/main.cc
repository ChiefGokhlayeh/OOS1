#include <iostream>
#include "mylist.hh"
#include "circle4.hh"

using namespace std;

// lab5/aufgabe3/app_lab5_aufgabe3
int main()
{
    Point p1(1, 1);
    Point p2(2, 2);
    Point p3(3, 3);
    Point p4(4, 4);
    cout << "Liste v1 erstellen ..." << endl;
    MyList v1;
    v1.PushBack(p1);
    v1.PushBack(p2);
    v1.PushBack(p3);
    cout << "Liste v1 ausgeben ..." << endl;
    v1.Print();
    cout << "Liste v1 in v2 kopieren ..." << endl;
    MyList v2(v1);
    cout << "Liste v2 ausgeben ..." << endl;
    v2.Print();
    cout << "Punkt am Beginn der Liste v2 verschieben ..." << endl;
    dynamic_cast<Point &>(v2.Front()).Move(10, 10);
    cout << "Liste v1 ausgeben ..." << endl;
    v1.Print();
    cout << "Liste v2 ausgeben ..." << endl;
    v2.Print();
    cout << "Groesse von v1: " << v1.Size() << endl;
    if (!v1.Empty())
    {
        v1.Clear();
    }
    cout << "Groesse von v1: " << v1.Size() << endl;
    v1.Print();
    v2.Print();
    cout << "Groesse von v2: " << v2.Size() << endl;
    v2.PushBack(p1);
    cout << "Groesse von v2: " << v2.Size() << endl;
    v2.Print();
    cout << "Punkt (4,4) hinten an v1 anhaengen ..." << endl;
    v1.PushBack(p4);
    cout << "Liste v1 an v2 anhaengen ..." << endl;
    v2 = v2 + v1;
    cout << "Liste v1 ausgeben ..." << endl;
    v1.Print();
    cout << "Liste v2 ausgeben ..." << endl;
    v2.Print();
    cout << "Liste mit Kreisen ..." << endl;
    Circle c1(p1, 1);
    Circle c2(p2, 2);
    MyList v3;
    v3.PushBack(c1);
    v3.PushBack(c2);
    v3.Print();
    return 0;
}
