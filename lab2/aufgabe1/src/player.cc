#include "player.hh"
#include "labyrinth.hh"

#include <cstdlib>

Player::Player(const MyString &mystr)
{
    name = mystr;
    coinCount = 0;
}

Player::Player(const char *cstr)
{
    name = MyString(cstr);
    coinCount = 0;
}

const Position &Player::GetPos() const
{
    return pos;
}

void Player::SetPos(const Position &pos)
{
    this->pos = pos;
}

void Player::SetDirection(Direction dir)
{
    pos.r = dir;
}

int Player::GetCoinCount() const
{
    return coinCount;
}

void Player::IncrementCoinCount()
{
    coinCount++;
}

const Player &Player::Step(const Labyrinth &lab)
{
    pos.Step(lab);
}

void Player::Turn(const Labyrinth &lab)
{
    Position postmp = pos;
    // Eine von 4 Richtungen auswählen
    int rint = rand() % 4;
    postmp.r = Direction(rint);
    while ((lab.GetCharAt(postmp)) == WALL)
    {
        rint = rand() % 4;
        postmp.r = Direction(rint);
    }
    pos.r = Direction(rint);
}
