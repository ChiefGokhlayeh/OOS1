#include "mystring.hh"
#include "pacman.hh"

#include <iostream>

char build = true;

int main()
{
    std::cout << "Moechten Sie zunächst ein Labyrinth bauen (j/n): ";
    std::cin >> build;
    Labyrinth lab;
    if (build == 'j')
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
