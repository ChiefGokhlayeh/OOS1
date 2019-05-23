#include "dvd.hh"

#include <iostream>

using namespace std;

DVD::DVD(string t, string v, int j, int d)
    : Medium(t, v, j, "DVD"), dauer(d)
{
}

void DVD::print() const
{
    Medium::print();
    cout << "Dauer:\t\t" << dauer << endl;
}
