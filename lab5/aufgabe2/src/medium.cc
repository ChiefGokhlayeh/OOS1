#include "medium2.hh"

#include <iostream>

using namespace std;

Medium::Medium(string t, string v, int j)
    : titel(t), verlag(v), jahr(j), ausleiher(nullptr), von(), bis()
{
}

string Medium::getTitel() const
{
    return titel;
}

const Person *Medium::getAusleiher() const
{
    return ausleiher;
}

void Medium::ausleihen(const Person &p, Datum von, Datum bis)
{
    ausleiher = &p;
    this->von = von;
    this->bis = bis;
}

void Medium::print() const
{
    cout << "----------------" << endl
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
