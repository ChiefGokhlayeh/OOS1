#ifndef POWERDRILL_HH_
#define POWERDRILL_HH_

#include "powertool.hh"

class PowerDrill : public PowerTool
{
public:
    PowerDrill(int power);

    void Print() const override;
};

#endif
