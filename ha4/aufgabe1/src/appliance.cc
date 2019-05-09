#include "appliance.hh"

#include <iostream>

using namespace std;

Appliance::Appliance(const string &name, double weight)
    : name(name), weight(weight)
{
}

const string &Appliance::GetName() const
{
    return name;
}

double Appliance::GetWeigth() const
{
    return weight;
}

void Appliance::SetWeight(double weight)
{
    this->weight = weight;
}

void Appliance::Print() const
{
    cout << "Gerätename:\t= " << GetName() << endl;
    cout << "Gewicht:\t= " << GetWeigth() << " Kg" << endl;
}
