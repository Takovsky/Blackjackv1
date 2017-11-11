#ifndef _CARD_H
#define _CARD_H

enum suit // symbol karty
{
  diamond,
  club,
  heart,
  spade
};
const suit sAll[] = {diamond, club, heart, spade}; // wszystkie symbole(uzywane w symbol++)
suit operator++(suit &, int);                      // inkrementacja symbolu

enum figure // figura karty
{
  two = 2,
  three,
  four,
  five,
  six,
  seven,
  eight,
  nine,
  ten,
  jack = 10,
  quenn = 10,
  king = 10,
  ace
};
const figure fAll[] = {two, three, four, five, six, seven, eight, nine, ten, jack, quenn, king, ace}; // wszystkie figury(uzywane w figura++)
figure operator++(figure &, int);                                                                     // inkrementacja figury

// klasa karty
class Card
{
public:
  int value() const { return static_cast<int>(_value); }   // zwracamy wartosc
  int symbol() const { return static_cast<int>(_symbol); } // zwracamy symbol
  Card() : _symbol(diamond), _value(two) {}                // konstruktor
  ~Card() {}
  void set(suit, figure); // setowanie karty

private:
  suit _symbol;  // symbol
  figure _value; // wartosc
};

#endif