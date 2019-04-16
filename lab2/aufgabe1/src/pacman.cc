#include "pacman.hh"

#if defined(USE_USER_CONIO)
#include "user_conio.h"
#elif defined(USE_NCURSES)
#include <ncurses.h>
#include <sstream>
#else
#include <conio.h>
#endif
#include <iostream>
#include <chrono>
#include <thread>
#include <unistd.h>

#if defined(USE_USER_CONIO)
#elif defined(USE_NCURSES)
#define KEY_Q ('Q')
#else
#define KEY_UP ('W')
#define KEY_LEFT ('A')
#define KEY_RIGHT ('D')
#define KEY_DOWN ('S')
#define KEY_Q ('Q')
#endif

using namespace std;
using namespace std::chrono;

PacMan::PacMan(Labyrinth &l, Player &sp, Player gArr[], int ghostCount)
{
    steps = 0;     // Anzahl der Spielschritte
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

#if defined(USE_NCURSES)
    nodelay(lab->GetWindowHandle(), TRUE);
#endif
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

int PacMan::CheckForInput()
{
    this_thread::sleep_for(chrono::milliseconds(300));
#if defined(USE_NCURSES)
    qiflush();
    int c = toupper(wgetch(lab->GetWindowHandle()));
    while (wgetch(lab->GetWindowHandle()) != ERR);
    return c;
#else
    if (_kbhit())
    {
        return toupper(getch());
    }
    else
    {
        return 'x';
    }
#endif
}

void PacMan::Play()
{
    // Das Spiel läuft solange noch Münzen im Labyrinth sind
    // und eine Geist nicht auf der Position des Spielers ist.
    // Temporäre Variable für die Keyboard-Eingabe
    int c = 'x';
    // Temporäre Variable, um die gewählte Richtung zu speichern
    Direction r = s->GetPos().r;
    // Position des Spielers einzeichnen
    lab->SetCharAt(CURSOR, s->GetPos());
    // Temporäre Variable für die Abbruchbedingung der Spielschleife
    bool cond = (coinCount > 1);
    while (cond)
    {
        c = CheckForInput();
        switch (c)
        {
        case KEY_UP:
            r = UP;
            break;
        case KEY_LEFT:
            r = LEFT;
            break;
        case KEY_RIGHT:
            r = RIGHT;
            break;
        case KEY_DOWN:
            r = DOWN;
            break;
        case KEY_Q:
            coinCount = 0;
            break;
        }
        s->SetDirection(r);
        // Einen Spielschritt ausführen
        Step();
        // Neue Spielsituation anzeigen
        lab->Print();
#if defined(USE_NCURSES)
        stringstream sbuff;
        sbuff << "Richtung: " << s->GetPos().r << endl;
        sbuff << "Gesammelte Muenzen: " << s->GetCoinCount() << endl;
        sbuff << "Verbleibende Muenzen: " << coinCount << endl;
        sbuff << steps << ". Schritt" << endl
              << endl;
        sbuff << "Zum Abbrechen q druecken" << endl;
        mvwprintw(lab->GetWindowHandle(), Labyrinth::maxRowCount + 1, 0, sbuff.str().c_str());
#else
        cout << "Richtung: " << s->GetPos().r << endl;
        cout << "Gesammelte Muenzen: " << s->GetCoinCount() << endl;
        cout << "Verbleibende Muenzen: " << coinCount << endl;
        cout << steps << ". Schritt" << endl
             << endl;
        cout << "Zum Abbrechen q druecken" << endl;
#endif
        // Prüfen, ob noch Münzen da sind
        // und ob der Spieler noch nicht gefangen wurde
        cond = (coinCount > 1);
        for (int i = 0; i < Labyrinth::maxGhostCount; i++)
        {
            cond = cond && !(s->GetPos().Equals(g[i]->GetPos()));
        }
    }
}
