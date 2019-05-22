#include "parallelogram.hh"
#include "rectangle.hh"

#include <iostream>

using namespace std;

int main()
{
    Paralellogram p(10, 20, 45);
    Rectangle r(40, 50);
    p.Print();
    p.SetA(15);
    p.SetPhi(50);
    r.Print();
    r.SetA(45);
    if (r.GetPhi() != 90.0)
    {
        cout << "Das ist doch kein Rechteck!" << endl;
    }
    r.Print();
    return 0;
}
