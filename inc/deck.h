#ifndef _DECK_H
#define _DECK_H

#include <vector>
#include <memory>
#include <card.h>
#define DECK_SIZE 52

class Deck : public std::vector<std::shared_ptr<Card>>
{
public:
  Deck() { reserve(DECK_SIZE); }
  ~Deck() {}
  void set();

  void swap(int, int);
private:
};

#endif