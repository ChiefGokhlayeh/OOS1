#include "employee.hh"
#include "manager.hh"
#include "worker.hh"

#include <iostream>

using namespace std;

void virtualMitPointern(const Angestellte *);
void virtualMitReferenz(const Angestellte &);

int main()
{
    Boss b("Gerd", "Mayer", 1000.00);
    b.print();
    cout << "Gehalt: " << b.einkommen() << endl;
    virtualMitPointern(&b);
    virtualMitReferenz(b);

    Arbeiter a("Rainer", "Mueller", 10.00, 40);
    a.print();
    cout << "Lohn: " << a.einkommen() << endl;
    virtualMitPointern(&a);
    virtualMitReferenz(a);
    return 0;
}

void virtualMitPointern(const Angestellte *angstP)
{
    angstP->print();
    cout << "Gehalt: " << angstP->einkommen() << endl;
}

void virtualMitReferenz(const Angestellte &angstR)
{
    angstR.print();
    cout << "Gehalt: " << angstR.einkommen() << endl;
}
