#ifndef VEHICLE_HH_
#define VEHICLE_HH_

#include <ostream>

#include "mystring2.hh"

class Vehicle
{
  private:
    MyString registration;
    const int vin;
    double km;

  public:
    static int counter;

    Vehicle();
    Vehicle(const char *model);

    void Drive(double km);

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &v);
};

#endif