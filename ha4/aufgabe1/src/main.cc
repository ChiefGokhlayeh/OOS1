#include "appliance.hh"
#include "freezer.hh"

int main()
{
    Appliance a("Bügeleisen", 1);
    a.Print();

    Freezer f;
    f.Print();

    f.SetWeight(50);
    f.SetVolume(75);
    f.Print();

    return 0;
}
