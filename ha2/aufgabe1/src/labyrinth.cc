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

void Labyrinth::Print() const
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
