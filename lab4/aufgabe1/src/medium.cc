#include "medium.hh"

#include <iostream>

using namespace std;

Medium::Medium(string t, string v, int j, string typ)
    : titel(t), verlag(v), jahr(j), typ(typ), ausleiher(nullptr), von(), bis()
{
}

string Medium::getTitel() const
{
    return titel;
}

string Medium::getTyp() const
{
    return typ;
}

Person *Medium::getAusleiher() const
{
    return ausleiher;
}

void Medium::ausleihen(Person &p, Datum von, Datum bis)
{
    ausleiher = &p;
    this->von = von;
    this->bis = bis;
}

void Medium::print() const
{
    cout << "----------------" << endl
         << typ << endl
         << "Titel:\t\t" << titel << endl
         << "Verlag:\t\t" << verlag << endl
         << "Jahr:\t\t" << jahr << endl
         << "Ausleiher:\t";
    if (ausleiher == nullptr)
    {
        cout << "kein" << endl;
    }
    else
    {
        ausleiher->print();
        cout << " von: " << von << " bis: " << bis << endl;
    }
}
