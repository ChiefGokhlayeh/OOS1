#ifndef PERSON2_HH_
#define PERSON2_HH_

#include <string>
using namespace std;

// Klasse f�r alle Personen, die Medien ausleihen k�nnen
class Person
{
    // Name der Person
    string name;
    // Dauer in Tagen, die die Person ein Medium ausleihen darf
    // wird von den abgelieteten Klassen festgelegt
    int ausleihdauer;

public:
    // Standardkonstruktor
    Person(string name, int dauer = 0);
    // den Namen zur�ckliefern
    string getName() const;
    // die Ausliehdauer zur�ckliefern
    int getAusleihdauer() const;
    // die Person auf der Konsole ausgeben
    virtual void print() const;
};

#endif
