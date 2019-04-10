#include "labyrinth.hh"
#include "position.hh"

#include <iostream>
#include <fstream>
#include <cstring>

#if defined(USE_USER_CONIO)
#include "user_conio.h"
#else
#include <conio.h>
#endif

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
}

Labyrinth::~Labyrinth()
{
}

void Labyrinth::Build()
{
    char c = 'x';
    int posx = maxColumnCount / 2;
    int posy = maxRowCount / 2;
    labyrinth[posy][posx] = CURSOR;
    Print();
    while (c != Q_KEY)
    {
        Print();
        cout << "Laufen mit Pfeiltasten. Beenden mit q." << endl;
        labyrinth[posy][posx] = PATH;
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
            posx = min(maxColumnCount - 2, posx + 1);
            break;
        case ARROW_DOWN_KEY:
            posy = min(maxRowCount - 2, posy + 1);
            break;
        case Q_KEY:
            break;
        }
        labyrinth[posy][posx] = CURSOR;
    }
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

void Labyrinth::Print()
{
    clear_console();
    for (auto &row : labyrinth)
    {
        cout << row;
    }
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

bool Labyrinth::IsCoinAt(Position &pos)
{
    return GetCharAt(pos) == COIN;
}

int Labyrinth::GetRowCount()
{
    return rowCount;
}

int Labyrinth::GetColumnCount()
{
    return columnCount;
}

int Labyrinth::GetGhostCount()
{
    return ghostCount;
}

int Labyrinth::GetCoinCount()
{
    return coinCount;
}

char Labyrinth::GetCharAt(Position &pos)
{
    return labyrinth[pos.posy][pos.posx];
}

void Labyrinth::Export(const char *filename)
{
    ofstream ofs(filename, ofstream::trunc);

    if (ofs.is_open())
    {
        for (auto &line : labyrinth)
        {
            ofs << line;
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
