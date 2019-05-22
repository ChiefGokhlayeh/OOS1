#include "powerscrewdriver.hh"

#include <iostream>

using namespace std;

PowerScrewDriver::PowerScrewDriver(int power)
    : PowerTool::PowerTool(power)
{
}

void PowerScrewDriver::Print() const
{
    cout << "Leistungsaufnahme als Schrauber: " << GetPower() << endl;
}
