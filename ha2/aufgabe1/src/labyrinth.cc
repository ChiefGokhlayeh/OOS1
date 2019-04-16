#include "labyrinth.hh"
#include "position.hh"

#include <iostream>
#include <fstream>
#include <cstring>

#if defined(USE_USER_CONIO)
#include "user_conio.h"
#elif defined(USE_NCURSES)
#include <ncurses.h>
#else
#include <conio.h>
#endif

#if defined(USE_USER_CONIO)
#define clear_console()         \
    do                          \
    {                           \
        cout << "\033[H\033[J"; \
    } while (0)
#elif defined(USE_NCURSES)
#define clear_console()
#define KEY_Q ('Q')
#else
#define clear_console() clrscr()
#define KEY_UP ('W')
#define KEY_LEFT ('A')
#define KEY_RIGHT ('D')
#define KEY_DOWN ('S')
#define KEY_Q ('Q')
#endif

extern int min(int a, int b);
extern int max(int a, int b);

using namespace std;

Labyrinth::Labyrinth()
{
    ghostCount = maxGhostCount;
    coinCount = 0;
    rowCount = maxRowCount;
    columnCount = maxColumnCount;
    Clear();

#if defined(USE_NCURSES)
    initscr();
    noecho();
    labWin = newwin(maxRowCount + 1, 80, 0, 0);
    keypad(labWin, TRUE);
    cbreak();
    refresh();
#endif
}

Labyrinth::~Labyrinth()
{
#if defined(USE_NCURSES)
    delwin(labWin);
    endwin();
#endif
}

void Labyrinth::Build()
{
    int c = 'x';
    int posx = maxColumnCount / 2;
    int posy = maxRowCount / 2;
    labyrinth[posy][posx] = CURSOR;
    do
    {
        Print();
        const char *info = "Laufen mit Pfeiltasten. Beenden mit 'Q'.";
#if defined(USE_NCURSES)
        mvwprintw(labWin, rowCount, 0, info);
        waddch(labWin, '\n');
#else
        cout << info << endl;
#endif
        labyrinth[posy][posx] = PATH;
#if defined(USE_NCURSES)
        c = toupper(wgetch(labWin));
#else
        c = toupper(getch());
#endif
        switch (c)
        {
        case KEY_UP:
            posy = max(1, posy - 1);
            break;
        case KEY_LEFT:
            posx = max(1, posx - 1);
            break;
        case KEY_RIGHT:
            posx = min(maxColumnCount - 2, posx + 1);
            break;
        case KEY_DOWN:
            posy = min(maxRowCount - 2, posy + 1);
            break;
        case KEY_Q:
            break;
        }
        labyrinth[posy][posx] = CURSOR;
    } while (c != KEY_Q);
}

void Labyrinth::Clear()
{
    for (auto &row : this->labyrinth)
    {
        memset(row, WALL, maxColumnCount);
        row[maxColumnCount] = NL;
        row[maxColumnCount + 1] = EOS;
    }
}

void Labyrinth::Print() const
{
#if defined(USE_NCURSES)
    for (int i = 0; i < rowCount; i++)
    {
        mvwprintw(labWin, i, 0, labyrinth[i]);
    }
    wrefresh(labWin);
#else
    clear_console();
    for (auto &row : labyrinth)
    {
        cout << row;
    }
#endif
}

void Labyrinth::PlaceCoins()
{
    coinCount = 0;
    for (auto &row : labyrinth)
    {
        for (int i = 0; i < columnCount; i++)
        {
            if (row[i] == PATH)
            {
                row[i] = COIN;
                coinCount++;
            }
        }
    }
}

bool Labyrinth::IsCoinAt(const Position &pos) const
{
    return GetCharAt(pos) == COIN;
}

int Labyrinth::GetRowCount() const
{
    return rowCount;
}

int Labyrinth::GetColumnCount() const
{
    return columnCount;
}

int Labyrinth::GetGhostCount() const
{
    return ghostCount;
}

int Labyrinth::GetCoinCount() const
{
    return coinCount;
}

#if defined(USE_NCURSES)
WINDOW *Labyrinth::GetWindowHandle() const
{
    return labWin;
}
#endif

char Labyrinth::GetCharAt(const Position &pos) const
{
    return labyrinth[pos.posy][pos.posx];
}

void Labyrinth::SetCharAt(char c, const Position &pos)
{
    labyrinth[pos.posy][pos.posx] = c;
}

void Labyrinth::SetCharAt(char c, const Position &posOld, const Position &posNew)
{
    SetCharAt(c, posNew);
    SetCharAt(PATH, posOld);
}

void Labyrinth::Export(const char *filename) const
{
    ofstream ofs(filename, ofstream::trunc);

    if (ofs.is_open())
    {
        for (const auto &line : labyrinth)
        {
            for (auto c : line)
            {
                if (c != EOS)
                {
                    if (c == CURSOR)
                    {
                        ofs << char(PATH);
                    }
                    else
                    {
                        ofs << c;
                    }
                }
            }
        }

        ofs.close();
    }
    else
    {
        cerr << "Unable to open filestream to file '" << filename << "'" << endl;
    }
}

void Labyrinth::Import(const char *filename)
{
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        for (int i = 0; i < maxRowCount; i++)
        {
            ifs.getline(labyrinth[i], maxColumnCount + 2);
            labyrinth[i][maxColumnCount] = NL;
            labyrinth[i][maxColumnCount + 1] = EOS;
        }

        ifs.close();
    }
    else
    {
        cerr << "Unable to open filestream to file '" << filename << "'" << endl;
    }
}
