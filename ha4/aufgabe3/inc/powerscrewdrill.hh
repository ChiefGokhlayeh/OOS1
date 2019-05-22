#ifndef POWERSCREWDRILL_HH_
#define POWERSCREWDRILL_HH_

#include "powerdrill.hh"
#include "powerscrewdriver.hh"

class PowerScrewDrill : public PowerDrill, public PowerScrewDriver
{
public:
    PowerScrewDrill(int drillPower, int screwDriverPower);

    void Print() const override;
};

#endif
