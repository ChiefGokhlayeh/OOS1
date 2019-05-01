#include "vehicle2.hh"

#include <iostream>

int Vehicle::counter = 0;

using namespace std;

int main()
{
    Vehicle f1("ES - H 123");
    cout << f1 << endl;
    f1.Drive(101.5);
    cout << f1 << endl;
    Vehicle f2("ES - M 4711");
    f2.Drive(10.57);
    cout << f2 << endl;

    cout << "Total kilometers: " << Vehicle::GetTotalKm() << endl;

    {
        Vehicle f3("ES - U 5721");
        f3.Drive(4.71);
        cout << f3 << endl;
        cout << "Total kilometers: " << Vehicle::GetTotalKm() << endl;
    }
    cout << "Total kilometers: " << Vehicle::GetTotalKm() << endl;
    return 0;
}
