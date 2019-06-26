#include "dvd2.hh"

#include <iostream>

using namespace std;

DVD::DVD(string t, string v, int j, int d)
    : Medium(t, v, j), dauer(d)
{
}

void DVD::print() const
{
    Medium::print();
    cout << "Typ:\t\tDVD" << endl;
    cout << "Dauer:\t\t" << dauer << endl;
}

DVD *DVD::clone() const
{
    return new DVD(*this);
}
