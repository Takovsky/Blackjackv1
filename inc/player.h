#ifndef _PLAYER_H
#define _PLAYER_H

#include <vector>
#include <card.h>
#include <memory>
#include <person.h>

class Player : public Person
{
public:
  Player(std::string name = "nn") : Person(_count, name) { _count++; }
  ~Player() { _count--; }
  unsigned int number() const { return _count; }

private:
  static unsigned int _count;
};

#endif