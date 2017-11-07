#ifndef _DECK_H
#define _DECK_H

#include <vector>
#include <memory>
#include <card.h>

class deck : private std::vector<std::shared_ptr<card>>
{
private:
    typedef std::vector<std::shared_ptr<card>> _deck;
  public:
    deck() { _deck::reserve(52); }
    ~deck() {}
    void set();
};

#endif