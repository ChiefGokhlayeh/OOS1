#include "powerdrill.hh"
#include "powerscrewdriver.hh"
#include "powerscrewdrill.hh"

#include <iostream>

using namespace std;

int main()
{
    PowerDrill drill(300);
    drill.Print();
    PowerScrewDriver screwdriver(500);
    screwdriver.Print();
    PowerScrewDrill screwdrill(400, 900);
    screwdrill.Print();
    return 0;
}
