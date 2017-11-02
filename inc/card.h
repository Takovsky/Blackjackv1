#ifndef _CARD_H
#define _CARD_H

class card
{
  public:
    int value() { return static_cast<int>(value); }

  private:
    enum suit
    {
        diamond,
        club,
        heart,
        spade
    };
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
    suit symbol;
    figure value;
};

#endif