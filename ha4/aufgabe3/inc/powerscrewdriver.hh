#ifndef POWERSCREWDRIVER_HH_
#define POWERSCREWDRIVER_HH_

#include "powertool.hh"

class PowerScrewDriver : public PowerTool
{
public:
    PowerScrewDriver(int power);

    void Print() const override;
};

#endif
