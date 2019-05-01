#include "vehicle.hh"

#include <ostream>

using namespace std;

double Vehicle::totalKm = 0;

double Vehicle::GetTotalKm()
{
    return Vehicle::totalKm;
}

Vehicle::Vehicle()
    : vin(Vehicle::counter + 1), registration(), km(0)
{
    Vehicle::counter++;
}

Vehicle::Vehicle(const char *model)
    : vin(Vehicle::counter + 1), registration(model), km(0)
{
    Vehicle::counter++;
}

Vehicle::~Vehicle()
{
    Vehicle::counter--;
    Vehicle::totalKm -= km;
}

void Vehicle::Drive(double km)
{
    this->km += km;
    Vehicle::totalKm += km;
}

ostream &operator<<(ostream &os, const Vehicle& v)
{
    os << "Kz = " << v.registration << " VIN = " << v.vin << " km = " << v.km;
    return os;
}
