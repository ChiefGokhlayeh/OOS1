#include "vehicle.hh"

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
    return 0;
}
