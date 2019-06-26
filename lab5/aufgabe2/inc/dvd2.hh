#ifndef DVD2_HH_
#define DVD2_HH_

#include "medium2.hh"

// Klasse für die DVDs als Spezialisierung von Medium
class DVD : public Medium
{
    // Abspieldauer der DVD
    const int dauer;

public:
    // Standardkonstruktor
    DVD(string t = "", string v = "", int j = 0, int d = 0);
    // die DVD auf der Konsole ausgeben
    void print() const override;

    DVD *clone() const override;
};

#endif
