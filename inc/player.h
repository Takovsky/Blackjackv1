#ifndef _PLAYER_H
#define _PLAYER_H

#include <vector> // vector
#include <person.h>

// klasa gracza
class Player : public Person
{
public:
  Player(std::string name = "nn") : Person(_count, name) { _count++; } // konstruktor
  ~Player() { _count--; }                                              // desktruktor
  unsigned int number() const { return _count; }                       // zwraca liczbe graczy
  unsigned int sum() const { return _sum; }                            // zwraca sume graczy
  bool checkCards();                                                   // sprawdza sume kart gracza; <20 = true
  bool checkBlackjack() { return sum() == 21 ? true : false; }         // sprawdza czy oczko; ==21 = true
                                                                       //
private:                                                               //
  static unsigned int _count;                                          // liczba graczy
};

#endif