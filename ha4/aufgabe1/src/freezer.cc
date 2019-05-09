#include "freezer.hh"

#include <iostream>

using namespace std;

Freezer::Freezer() : Appliance("Gefrierschrank", 40), volume(30)
{
}

Freezer::Freezer(double volume) : Appliance("Gefrierschrank", 40), volume(volume)
{
}

double Freezer::GetVolume() const
{
    return volume;
}

void Freezer::SetVolume(double volume)
{
    this->volume = volume;
}

void Freezer::Print() const
{
    Appliance::Print();
    cout << "Volumen:\t= " << volume << " L" << endl;
}
