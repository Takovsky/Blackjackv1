#ifndef _CROUPIER_H
#define _CROUPIER_H

#include <memory>
#include <deck.h>
#include <card.h>

class Croupier
{
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
    static void shuffle(Deck d) { _crp->doShuffle(d); }

  private:
    static std::unique_ptr<Croupier> _crp;
    Croupier() { _crp.release(); }
    void doShuffle(Deck &);
};

#endif