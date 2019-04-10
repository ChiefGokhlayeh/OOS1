#include "mystring.hh"
#include "pacman.hh"

const bool build = false;

int main()
{
    Labyrinth lab;
    if (build)
    {
        lab.Build();
        lab.Export("lab.txt");
    }
    else
    {
        lab.Import("lab.txt");
        lab.PlaceCoins();
        Player s("Demo");
        Player g[Labyrinth::maxGhostCount] = {Player("Geist 1"),
                                  Player("Geist 2"),
                                  Player("Geist 3")};
        PacMan pm(lab, s, g, Labyrinth::maxGhostCount);
        pm.Play();
    }
}
