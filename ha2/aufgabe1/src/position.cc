// Datei Position.cpp
#include "position.hh"
#include "labyrinth.hh"

int max(int x, int y)
{
    return (x <= y) ? y : x;
}

int min(int x, int y)
{
    return (x <= y) ? x : y;
}

Position::Position(int x, int y)
{
    posx = x;
    posy = y;
}

// Schritt nach vorne in Richtung r um einen Schritt
// Es kann aber nicht in Mauern hineingelaufen werden
// *this wird entsprechend geändert
// Der int mode = 0 gibt an, dass die Mauern berücksichtigt werden.
// Wenn int != 0, dann kann auch durch Mauern gelaufen werden.
// Dies ist für das Erstellen von Labyrinthen notwendig.
const Position &Position::Step(const Labyrinth &lab, int mode)
{
    Position tmp = *this;
    switch (r)
    {
    case Direction::UP:
        tmp.posy = max(1, posy - 1);
        break;
    case Direction::LEFT:
        tmp.posx = max(1, posx - 1);
        break;
    case Direction::RIGHT:
        tmp.posx =
            min(lab.GetColumnCount() - 2, posx + 1);
        break;
    case Direction::DOWN:
        tmp.posy =
            min(lab.GetRowCount() - 2, posy + 1);
        break;
    }
    if (mode != 0 || lab.GetCharAt(tmp) != WALL)
    {
        *this = tmp;
    }
    return *this;
}

// Zwei Positionen vergleichen,
// liefert true, wenn x und y gleich
bool Position::Equals(const Position &p) const
{
    return (posx == p.posx && posy == p.posy);
}
