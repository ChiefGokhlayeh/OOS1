#include "powertool.hh"

#include <iostream>

using namespace std;

PowerTool::PowerTool(int power)
    : power(power)
{
}

int PowerTool::GetPower() const
{
    return power;
}

void PowerTool::SetPower(int power)
{
    this->power = power;
}

void PowerTool::Print() const
{
    cout << "Leistungsaufnahme: " << power << "W" << endl;
}
