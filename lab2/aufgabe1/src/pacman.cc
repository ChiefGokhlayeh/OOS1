#include "pacman.hh"

#if defined(USE_USER_CONIO)
#include "user_conio.h"
#else
#include <conio.h>
#endif
#include <iostream>
#include <chrono>
#include <thread>
#include <unistd.h>

using namespace std;
using namespace std::chrono;

PacMan::PacMan(Labyrinth &l, Player &sp, Player gArr[], int ghostCount)
{
    steps = 0; // Anzahl der Spielschritte
    coinCount = 0; // Anzahl der Münzen im Labyrinth
    lab = &l;
    s = &sp;
    for (int i = 0; i < ghostCount; i++)
    {
        g[i] = &gArr[i];
    }
    // Spieler in die Mitte des Labyrinths setzen
    Position centre(lab->GetColumnCount() / 2, lab->GetRowCount() / 2);
    centre.r = UP;
    s->SetPos(centre);
    // Anzahl der Münzen vom Labyrinth übernehmen
    coinCount = lab->GetCoinCount();
}

// Einen Schritt im Spiel ausführen
void PacMan::Step()
{
    // Schritte zählen
    steps++;
    // Aktuelle Position des Spielers merken,
    // so dass sie mit PATH überschrieben werden kann.
    Position postmp = s->GetPos();
    // Den Spieler einen Schritt machen lassen.
    s->Step(*lab);
    // Wenn beim neuen Schritt eine Münze gefunden wurde ...
    if (lab->IsCoinAt(s->GetPos()))
    {
        // Anzahl der gesammelten Münzen des Spielers erhöhen
        s->IncrementCoinCount();
        // Anzahl der vorhandenen Münzen reduzieren
        coinCount--;
    }
    // den getanen Schritt des Spielers einzeichnen
    lab->SetCharAt(PATH, postmp, s->GetPos());
    lab->SetCharAt(CURSOR, s->GetPos());
    // Dem Spieler 5 Schritte Vorsprung vor den Geistern lassen
    if (steps == 5)
    {
        Position centre(lab->GetColumnCount() / 2, lab->GetRowCount() / 2);
        for (int i = 0; i < Labyrinth::maxGhostCount; i++)
        {
            g[i]->SetPos(centre);
            lab->SetCharAt(GHOST, g[i]->GetPos());
        }
    }
    // Jetzt laufen die Geister
    if (steps > 5)
    {
        for (int i = 0; i < Labyrinth::maxGhostCount; i++)
        {
            // Geist-Zeichen löschen
            lab->SetCharAt(PATH, g[i]->GetPos());
            // Geist wählt zufällig seine Schrittrichtung
            g[i]->Turn(*lab);
            // Geist macht seinen Schritt
            g[i]->Step(*lab);
        }
        // Geister einzeichnen
        for (int i = 0; i < Labyrinth::maxGhostCount; i++)
        {
            // Geister sammeln Münzen
            if (lab->IsCoinAt(g[i]->GetPos()))
            {
                // Anzahl der vorhandenen Münzen reduzieren
                coinCount--;
            }
            // Geist einzeichnen
            lab->SetCharAt(GHOST, g[i]->GetPos());
        }
    }
}

void PacMan::Play()
{
    // Das Spiel läuft solange noch Münzen im Labyrinth sind
    // und eine Geist nicht auf der Position des Spielers ist.
    // Temporäre Variable für die Keyboard-Eingabe
    char c = 'x';
    // Temporäre Variable, um die gewählte Richtung zu speichern
    Direction r = s->GetPos().r;
    // Position des Spielers einzeichnen
    lab->SetCharAt(CURSOR, s->GetPos());
    // Temporäre Variable für die Abbruchbedingung der Spielschleife
    bool cond = (coinCount > 1);
    while (cond)
    {
        // Eine Weile warten (C++11)
        this_thread::sleep_for(chrono::milliseconds(700));
        if (_kbhit())
        { // wenn Taste gedrückt wurde ...
            c = toupper(getch());
            switch (int(c))
            {
            case ARROW_UP_KEY:
                r = UP;
                break;
            case ARROW_LEFT_KEY:
                r = LEFT;
                break;
            case ARROW_RIGHT_KEY:
                r = RIGHT;
                break;
            case ARROW_DOWN_KEY:
                r = DOWN;
                break;
            case Q_KEY:
                coinCount = 0;
                break;
            }
            s->SetDirection(r);
        }
        // Einen Spielschritt ausführen
        Step();
        // Neue Spielsituation anzeigen
        lab->Print();
        cout << "Richtung: " << s->GetPos().r << endl;
        cout << "Gesammelte Muenzen: " << s->GetCoinCount() << endl;
        cout << "Verbleibende Muenzen: " << coinCount << endl;
        cout << steps << ". Schritt" << endl
             << endl;
        cout << "Zum Abbrechen q druecken" << endl;
        // Prüfen, ob noch Münzen da sind
        // und ob der Spieler noch nicht gefangen wurde
        cond = (coinCount > 1);
        for (int i = 0; i < Labyrinth::maxGhostCount; i++)
        {
            cond = cond && !(s->GetPos().Equals(g[i]->GetPos()));
        }
    }
}
