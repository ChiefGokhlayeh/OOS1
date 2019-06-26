#include "library2.hh"

#include <iostream>

using namespace std;

Bibliothek::Bibliothek(int maxAnz)
    : maxAnz(maxAnz),
      medien(new Medium *[maxAnz]),
      anz(0)
{
}

Bibliothek::~Bibliothek()
{
    for (int i = 0; i < anz; ++i)
    {
        if (medien[i] != nullptr)
        {
            delete medien[i];
            medien[i] = NULL;
        }
    }
    delete[] medien;
}

void Bibliothek::mediumBeschaffen(const Medium &medium)
{
    if (anz < maxAnz)
    {
        medien[anz] = medium.clone();
        anz++;
    }
}

void Bibliothek::mediumSuchen(string suchwort)
{
    cout << "Suche nach \"" << suchwort << "\". Ergebnis:" << endl
         << endl;
    for (int i = 0; i < anz; ++i)
    {
        if (string::npos != medien[i]->getTitel().find(suchwort))
        {
            cout << "Medium " << i << ":" << endl;
            medien[i]->print();
            cout << endl;
        }
    }
}

void Bibliothek::mediumAusleihen(int nr, const Person &p, Datum d)
{
    if (nr <= anz)
    {
        medien[nr]->ausleihen(p, d, d + p.getAusleihdauer());
    }
}

void Bibliothek::print() const
{
    cout << "Buchungskatalog:" << endl;
    for (int i = 0; i < anz; i++)
    {
        medien[i]->print();
    }
    cout << endl;
}
