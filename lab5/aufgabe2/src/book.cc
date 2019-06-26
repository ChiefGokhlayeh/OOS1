#include "book2.hh"

#include <iostream>

using namespace std;

Buch::Buch(string t, string a, string v, int jahr)
    : Medium::Medium(t, v, jahr)
{
    autor = a;
}
void Buch::print() const
{
    Medium::print();
    cout << "Typ:\t\tBook" << endl;
    cout << "Autor:\t\t" << autor << endl;
}

Buch *Buch::clone() const
{
    return new Buch(*this);
}
