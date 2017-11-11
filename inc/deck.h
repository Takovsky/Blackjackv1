#ifndef _DECK_H
#define _DECK_H

#include <vector> // vector
#include <memory> // unique_ptr
#include <card.h>

#define DECK_SIZE 52 // rozmiar talii kart

class Deck : public std::vector<std::unique_ptr<Card>>
{
public:
  ~Deck() {}

protected:
  Deck() { reserve(DECK_SIZE); } // talia ma 52 miejsca, wiec tyle rezerwujemy
  void set();                    // setujemy karty
  void swap(int, int);           // zamieniamy karty ze soba(do shufflowania)
};

#endif