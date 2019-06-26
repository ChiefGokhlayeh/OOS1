#ifndef BOOK2_HH_
#define BOOK2_HH_

#include "medium2.hh"

// Klasse für die Bücher als Spezialisierung von Medium
class Buch : public Medium
{
    // Autor(en) des Buches
    string autor;

public:
    // Standardkonstruktor
    Buch(string t = "", string a = "", string v = "", int jahr = 0);
    // das Buch auf der Konsole ausgeben
    void print() const override;

    Buch *clone() const override;
};

#endif
