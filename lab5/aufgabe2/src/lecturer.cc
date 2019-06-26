#include "lecturer2.hh"

#include <iostream>

using namespace std;

Dozent::Dozent(string name, int prfrNr)
    : Person(name, 90)
{
    this->prfrNr = prfrNr;
}

void Dozent::print() const
{
    Person::print();
}
