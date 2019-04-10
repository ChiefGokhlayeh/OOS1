#ifndef PLAYER_HH_
#define PLAYER_HH_

#include "mystring.hh"
#include "position.hh"

class Player
{
public:
  Player(const MyString &mystr);
  Player(const char *cstr);

  const Position &GetPos() const;
  void SetPos(const Position &pos);
  void SetDirection(Direction dir);
  int GetCoinCount() const;
  void IncrementCoinCount();
  const Player &Step(const Labyrinth &lab);
  void Turn(const Labyrinth &lab);
private:
  MyString name;
  Position pos;
  int coinCount;
};

#endif
