#ifndef _CARD_H
#define _CARD_H

enum suit
{
  diamond,
  club,
  heart,
  spade
};
const suit sAll[] = {diamond, club, heart, spade};
suit operator++(suit &, int);

enum figure
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
const figure fAll[] = {two, three, four, five, six, seven, eight, nine, ten, jack, quenn, king, ace};
figure operator++(figure &, int);

class Card
{
public:
  int value() const { return static_cast<int>(_value); }
  int symbol()const { return static_cast<int>(_symbol); }
  Card() : _symbol(diamond), _value(two) {}
  ~Card() {}
  void set(suit, figure);

protected:
  // Card(suit s = diamond, figure f = two) { set(s, f); }

private:
  suit _symbol;
  figure _value;
};

#endif