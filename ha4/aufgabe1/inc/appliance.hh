#ifndef APPLIANCE_HH_
#define APPLIANCE_HH_

#include <string>

class Appliance
{
private:
    const std::string name;
    double weight;

public:
    Appliance(const std::string &name, double weight);

    const std::string &GetName() const;
    double GetWeigth() const;
    void SetWeight(double weight);

    virtual void Print() const;
};

#endif
