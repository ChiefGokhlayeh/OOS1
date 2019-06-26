#ifndef STUDENT2_HH_
#define STUDENT2_HH_

#include "person2.hh"

// Klasse Student als Spezialisierung von Person
class Student : public Person
{
    // Matrikelnummer des Studenten/der Studentin
    int matNr;

public:
    // Standardkonstruktor
    Student(string name, int matNr);
    // Student auf der Konsole ausgeben
    void print() const;
};

#endif
