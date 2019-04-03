#include <iostream>
#include <cstring>

#if !(defined(USE_USER_CONIO)) && !(defined(USE_NCURSES)) && !(defined(USE_CONIO))
#if defined(__GNUC__)
#define USE_NCURSES
#elif defined(_MSC_VER)
#define USE_CONIO
#endif
#endif

#if defined(USE_USER_CONIO)
#include "user_conio.h"
#elif defined(USE_NCURSES)
#include <ncurses.h>
#warning "CURRENTLY BUGGY!!!"
#else
#include <conio.h>
#endif

using namespace std;

#if defined(USE_NCURSES)
#define clear_console() \
    do                  \
    {                   \
        clear();        \
    } while (0)

#define ARROW_UP_KEY ('W')
#define ARROW_LEFT_KEY ('A')
#define ARROW_RIGHT_KEY ('D')
#define ARROW_DOWN_KEY ('S')
#define Q_KEY ('Q')
#else
#define clear_console()         \
    do                          \
    {                           \
        cout << "\033[H\033[J"; \
    } while (0)

#define ARROW_UP_KEY ('W')
#define ARROW_LEFT_KEY ('A')
#define ARROW_RIGHT_KEY ('D')
#define ARROW_DOWN_KEY ('S')
#define Q_KEY ('Q')
#endif

// Größe des Labyrinths
const int kZeilen = 11;
const int kSpalten = 11;

// Zeichen, die im Labyrinth vorkommen k�nnen,
// NL = new line, EOS = end of string
enum Symbole
{
    MAUER = '#',
    WEG = ' ',
    MUENZE = ':',
    NL = '\n',
    EOS = '\0',
    ICH = 'X',
    GEIST = 'G'
};

// Das Labyrinth als char-Array
// Die vorletzte Spalte speichert ein Zeilenendezeichen \n
// und die letzte ein \0-Zeichen, damit die Ausgabe leichter wird.
char labyrinth[kZeilen][kSpalten + 2];

// Labyrinth mit # füllen
void initialisieren()
{
    for (auto &zeile : labyrinth)
    {
        memset(zeile, MAUER, kSpalten);
        zeile[kSpalten] = NL;
        zeile[kSpalten + 1] = EOS;
    }
}

// Labyrinth auf dem Bildschirm ausgeben
void drucken()
{
    // Console frei machen
    clear_console();
    // Labyrinth ausgeben
    for (auto &zeile : labyrinth)
    {
#if defined(USE_NCURSES)
        addstr(zeile);
#else
        cout << zeile;
#endif
    }
}

// Durch Herumlaufen werden Wege im Labyrinth erzeugt
void erzeugen()
{
    char c = 'x';
    int posx = kSpalten / 2;
    int posy = kZeilen / 2;
    labyrinth[posy][posx] = ICH;
    drucken();
    while (c != Q_KEY)
    {
        drucken();
#if defined(USE_NCURSES)
        printw("Laufen mit Pfeiltasten. Beenden mit q.\n");
#else
        cout << "Laufen mit Pfeiltasten. Beenden mit q." << endl;
#endif
        labyrinth[posy][posx] = WEG;
        c = toupper(getch());
        switch (int(c))
        {
        case ARROW_UP_KEY:
            posy = max(1, posy - 1);
            break;
        case ARROW_LEFT_KEY:
            posx = max(1, posx - 1);
            break;
        case ARROW_RIGHT_KEY:
            posx = min(kSpalten - 2, posx + 1);
            break;
        case ARROW_DOWN_KEY:
            posy = min(kZeilen - 2, posy + 1);
            break;
        case Q_KEY:
            break;
        }
        labyrinth[posy][posx] = ICH;
    }
}

int main()
{
#if defined(USE_NCURSES)
    initscr();
    keypad(stdscr, TRUE);
    noecho();
#endif

    initialisieren();
    drucken();
    erzeugen();

#if defined(USE_NCURSES)
    endwin();
#endif
}
