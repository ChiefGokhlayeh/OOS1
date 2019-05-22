#ifndef POWERTOOL_HH_
#define POWERTOOL_HH_

class PowerTool
{
private:
    int power;

public:
    PowerTool(int watt);

    int GetPower() const;
    void SetPower(int power);

    virtual void Print() const;
};

#endif
