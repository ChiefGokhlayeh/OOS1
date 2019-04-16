#ifndef LABYRINTH_HH_
#define LABYRINTH_HH_

#include "position.hh"

#if defined(USE_NCURSES)
#include <ncurses.h>
#endif

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
public:
  static constexpr int maxRowCount = 11;
  static constexpr int maxColumnCount = 11;
  static constexpr int maxGhostCount = 3;

  Labyrinth();
  ~Labyrinth();

  void Build();
  void Clear();
  void Print() const;
  void PlaceCoins();
  bool IsCoinAt(const Position &pos) const;

  int GetRowCount() const;
  int GetColumnCount() const;
  int GetGhostCount() const;
  int GetCoinCount() const;
#if defined(USE_NCURSES)
  WINDOW *GetWindowHandle() const;
#endif

  char GetCharAt(const Position &pos) const;
  void SetCharAt(char c, const Position &pos);
  void SetCharAt(char c, const Position &posOld, const Position &posNew);

  void Export(const char *filename) const;
  void Import(const char *filename);

private:
  char labyrinth[maxRowCount][maxColumnCount + 2];
  int ghostCount;
  int coinCount;
  int rowCount;
  int columnCount;
#if defined(USE_NCURSES)
  WINDOW *labWin;
#endif
};

#endif
