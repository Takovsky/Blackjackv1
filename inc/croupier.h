#ifndef _CROUPIER_H
#define _CROUPIER_H

#include <memory>
#include <deck.h>
#include <card.h>
#include <player.h>

class Croupier : private Deck
{
  private:
    typedef Deck _deck;

  public:
    ~Croupier() {}
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
    static void giveCard(Player &p) { _crp->doGiveCard(p); }
    static void setDeck() { _crp->doSetDeck(); }

  private:
    void doSetDeck() { _deck::set(); }
    void doGiveCard(Player &);
    static std::unique_ptr<Croupier> _crp;
    Croupier() { _crp.release(); }
    void doShuffle();
};

#endif