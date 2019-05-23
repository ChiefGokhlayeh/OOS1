#include "book.hh"

#include <iostream>

using namespace std;

Buch::Buch(string t, string a, string v, int jahr)
    : Medium::Medium(t, v, jahr, "Buch")
{
    autor = a;
}
void Buch::print() const
{
    Medium::print();
    cout << "Autor:\t\t" << autor << endl;
}
