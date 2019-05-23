#ifndef LECTURER_HH_
#define LECTURER_HH_

#include "person.hh"

// Klasse Dozent als Spezialisierung von Person
class Dozent : public Person
{
    // Pr�fernummer des Dozenten
    int prfrNr;

public:
    // Standardkosntruktor
    Dozent(string name, int prfrNr);
    // Dozenten auf der Konsole ausgeben
    void print() const;
};

#endif
