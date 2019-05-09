#ifndef FREEZER_HH_
#define FREEZER_HH_

#include "appliance.hh"

#include <string>

class Freezer : public Appliance
{
private:
    double volume;

public:
    Freezer();
    Freezer(double volume);

    double GetVolume() const;
    void SetVolume(double volume);

    void Print() const override;
};

#endif
