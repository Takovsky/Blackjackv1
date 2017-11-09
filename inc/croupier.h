#ifndef _CROUPIER_H
#define _CROUPIER_H

#include <memory>
#include <deck.h>
#include <card.h>
#include <player.h>
#include <person.h>

class Croupier : private Deck, public Person
{
private:
  typedef Deck _deck;

public:
  ~Croupier() { _crp.release(); }
  static bool getInstance()
  {
    if (!_crp)
    {
      _crp = std::unique_ptr<Croupier>(new Croupier);
      return true;
    }
    else
      return false;
  }
  static void shuffle() { _crp->doShuffle(); }
  static void giveCard(Person &p) { _crp->doGiveCard(p); }
  static void takeCard() { _crp->doGiveCard(*_crp); }
  static void setDeck() { _crp->doSetDeck(); }
  static void clearTable()
  {
    _crp->_deck::clear();
    _crp->clearCards();
  }

private:
  std::string _name;
  int _id;
  void doSetDeck() { _deck::set(); }
  void doGiveCard(Person &);
  static std::unique_ptr<Croupier> _crp;
  Croupier() : Person(-1, "Croupier") {}
  void doShuffle();
};

#endif