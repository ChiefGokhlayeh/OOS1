#include "student2.hh"

#include <iostream>

using namespace std;

Student::Student(string name, int matNr)
    : Person(name, 30), matNr(matNr)
{
}

void Student::print() const
{
    Person::print();
}
