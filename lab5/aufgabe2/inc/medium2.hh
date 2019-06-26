#ifndef MEDIUM2_HH_
#define MEDIUM2_HH_

#include <string>
#include "date2.hh"
#include "person2.hh"
using namespace std;

// Klasse f�r die Medien, die in der Bibliothek ausgeliehen werden
// k�nnen
class Medium
{
    // Titel des Mediums
    const string titel;
    // Verlag, der das Medium herausgibt
    const string verlag;
    // Jahr, in dem das Medium ver�ffentlicht wurde
    const int jahr;
    // ausgeliehen von
    const Person *ausleiher;
    // ausgeliehen am
    Datum von;
    // ausgeliehen bis
    Datum bis;

public:
    // Konstruktor
    Medium(string t = "", string v = "", int j = 0);
    // Titel zur�ckliefern
    string getTitel() const;
    // Ausleiher zur�ckliefern
    const Person *getAusleiher() const;
    // das Mediuem "ausleihen", d.h. Person p, von und bis eintragen
    void ausleihen(const Person &p, Datum von, Datum bis);
    // Medium in der Konsole ausgeben
    virtual void print() const;

    virtual Medium *clone() const = 0;
};

#endif
