#include "employee.hh"

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

Angestellte::Angestellte(const char *vn, const char *nn)
{
    vorname = new char[strlen(vn) + 1];
    strcpy(vorname, vn);
    nachname = new char[strlen(nn) + 1];
    strcpy(nachname, nn);
}

Angestellte::~Angestellte()
{
    delete[] vorname;
    delete[] nachname;
}

const char *Angestellte::getVorname() const
{
    return vorname;
}

const char *Angestellte::getNachname() const
{
    return nachname;
}

void Angestellte::print() const
{
    cout << vorname << ", " << nachname << endl;
}
