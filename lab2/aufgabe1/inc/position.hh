#ifndef POSITION_HH_
#define POSITION_HH_

// Vorwärtsdeklaration der Klasse Labyrinth
class Labyrinth;

// Die Laufrichtung (Orientierung) als Aufz�hlungstypen
enum Direction
{
    RIGHT,
    LEFT,
    UP,
    DOWN
};

// Klasse Position
// Speichert die Position (x,y) und Laufrichtung eines Objektes
// im Labyrinth
// Als struct realisiert, damit später direkt auf posx und posy
// zugegriffen werden kann.
struct Position
{
    // Position in den Spalten
    int posx;
    // Position in den Zeilen
    int posy;
    // Richtung, in die jemand orientiert ist
    Direction r;
    // Konstruktor mit posx (Spalten) und posy (Zeilen)
    Position(int = 0, int = 0);
    // Schritt nach vorne in Richtung r um einen Schritt
    // *this wird entsprechend geändert
    // Der int = 0 gibt an, dass die Mauern berücksichtigt werden.
    // Wenn int != 0, dann kann auch durch Mauern gelaufen werden.
    // Dies ist für das Erstellen von Labyrinthen notwendig.
    const Position &Step(const Labyrinth &, int = 0);
    // Zwei Positionen vergleichen,
    // liefert true, wenn x und y gleich
    bool Equals(const Position &) const;
};

#endif
