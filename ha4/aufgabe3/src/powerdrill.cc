#include "powerdrill.hh"

#include <iostream>

using namespace std;

PowerDrill::PowerDrill(int power)
    : PowerTool::PowerTool(power)
{
}

void PowerDrill::Print() const
{
    cout << "Leistungsaufnahme als Bohrer: " << GetPower() << endl;
}
