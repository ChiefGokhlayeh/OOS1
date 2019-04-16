#ifndef PACMAN_HH_
#define PACMAN_HH_

#include "labyrinth.hh"
#include "player.hh"

class PacMan
{
  Labyrinth *lab;                      // Labyrinth für das Spiel
  Player *s;                           // Spieler, der das Spiel spielt
  Player *g[Labyrinth::maxGhostCount]; // Geister, die den Spieler jagen
  int steps;                           // Anzahl der Spielschritte
  int coinCount;                       // Anzahl der Münzen im Labyrinth
public:
  // Konstruktor
  PacMan(Labyrinth &l, Player &sp, Player gArr[], int ghostCount);
  // Einen Schritt im Spiel ausführen
  void Step();
  // Spiel spielen
  void Play();
  int CheckForInput();
};

#endif
