#include "powerscrewdrill.hh"

#include <iostream>

using namespace std;

PowerScrewDrill::PowerScrewDrill(int drillPower, int screwDriverPower)
    : PowerDrill::PowerDrill(drillPower), PowerScrewDriver::PowerScrewDriver(screwDriverPower)
{
}

void PowerScrewDrill::Print() const
{
    PowerDrill::Print();
    PowerScrewDriver::Print();
}
