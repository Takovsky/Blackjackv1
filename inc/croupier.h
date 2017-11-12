#ifndef _CROUPIER_H
#define _CROUPIER_H

#include <list>   // list
#include <memory> // smart ptr
#include <person.h>
#include <player.h>
#include <deck.h>
#include <card.h>

//klasa krupiera, singleton
class Croupier : private Deck, public Person
{
private:
  typedef Deck _deck; // talia kart w posiadaniu krupiera

public:
  ~Croupier() { _crp.release(); } // uwalniamy wskaznik przy wywolaniu destruktora
  static bool getInstance()       // bierzemu instancje krupiera
  {
    if (!_crp)
    {
      _crp = std::unique_ptr<Croupier>(new Croupier);
      return true;
    }
    else
      return false;
  }
  static bool play(std::list<std::shared_ptr<Player>> players) { return _crp->doPlay(players); } // koncowa gra krupiera, kiedy gracze juz podjeli decyzje
  static void shuffle() { _crp->doShuffle(); }                                                   // tasowanie kart
  static void giveCard(Person &p) { _crp->doGiveCard(p); }                                       // podanie karty graczowi
  static void takeCard() { _crp->doGiveCard(*_crp); }                                            // wydanie karty samemu sobie
  static void setDeck() { _crp->doSetDeck(); }                                                   // ustawia talie
  static unsigned int sum() { return _crp->_sum; }                                               // zwraca sume kart krupiera
  static int firstCard() { return (*_crp->ccBegin())->value(); }
  static void clearTable() // czysci stol(usuwa swoje karty i talie)
  {
    _crp->_deck::clear();
    _crp->clearCards();
  }

private:
  Croupier() : Person(-1, "Croupier") {}                                                   // konstruktor
  static std::unique_ptr<Croupier> _crp;                                                   // obiekt krupiera
  void doSetDeck() { _deck::set(); }                                                       // ustawia talie
  void doGiveCard(Person &);                                                               // podaje karte
  void doShuffle();                                                                        // tasowanie kart
  bool doPlay(std::list<std::shared_ptr<Player>>);                                         // koncowa gra krupiera
  static std::vector<std::unique_ptr<Card>>::iterator ccBegin() { return _crp->cBegin(); } // iteratory do poczatku i konca kart krupiera
  static std::vector<std::unique_ptr<Card>>::iterator ccEnd() { return _crp->cEnd(); }     //
};

#endif