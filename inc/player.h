#ifndef _PLAYER_H
#define _PLAYER_H

#include <vector>
#include <card.h>
#include <memory>

class Player : private std::vector<std::unique_ptr<Card>>
{
private:
  typedef std::vector<std::unique_ptr<Card>> _cards;

public:
  Player(int id = _count, std::string name = "nn") : _id(id), _name(name) { _count++; }
  ~Player() {}
  unsigned int sum() const { return _sum; }
  unsigned int number() const { return _count; }
  unsigned int id() const { return _id; }
  std::string name() const { return _name; }
  void pushCard(std::unique_ptr<Card> c) { _cards::push_back(std::move(c)); }
  _cards::iterator end() { return _cards::end() - 1; }

private:
  unsigned int _id;
  std::string _name;
  static unsigned int _count;
  unsigned int _sum;
};

#endif