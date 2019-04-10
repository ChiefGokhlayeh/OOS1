#ifndef LABYRINTH_HH_
#define LABYRINTH_HH_

#include "position.hh"

enum Symbols
{
    WALL = '#',
    PATH = ' ',
    COIN = ':',
    NL = '\n',
    EOS = '\0',
    CURSOR = 'X',
    GHOST = 'G'
};

class Labyrinth
{
  private:
    static constexpr int maxRowCount = 11;
    static constexpr int maxColumnCount = 11;
    static constexpr int maxGhostCount = 3;

    char labyrinth[maxRowCount][maxColumnCount + 2];
    int ghostCount;
    int coinCount;
    int rowCount;
    int columnCount;
  public:
    Labyrinth();
    ~Labyrinth();

    void Build();
    void Clear();
    void Print();
    void PlaceCoins();
    bool IsCoinAt(Position &pos);

    int GetRowCount();
    int GetColumnCount();
    int GetGhostCount();
    int GetCoinCount();

    char GetCharAt(Position &pos);

    void Export(const char* filename);
    void Import(const char* filename);
};

#endif
