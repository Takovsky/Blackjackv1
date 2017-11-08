#ifndef _DECK_H
#define _DECK_H

#include <vector>
#include <memory>
#include <card.h>

#define DECK_SIZE 52

class Deck : public std::vector<std::unique_ptr<Card>>
{
public:
  ~Deck() {}

protected:
  Deck() { reserve(DECK_SIZE); }
  void set();
  void swap(int, int);

private:
};

#endif