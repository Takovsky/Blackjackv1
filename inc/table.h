#ifndef _TABLE_H
#define _TABLE_H

#include <list>   // list
#include <memory> // smart ptr
#include <player.h>
#include <croupier.h>

//klasa stolu zarzadzajaca cala rozgrywka
class Table : private std::list<std::shared_ptr<Player>>
{
private:
  typedef std::list<std::shared_ptr<Player>> _players; // lista graczy przy stole

public:
  ~Table() { _table.release(); }
  static bool getInstance() // instancja stolu
  {
    if (!_table)
    {
      _table = std::unique_ptr<Table>(new Table);
      return true;
    }
    else
      return false;
  }
  static void addPlayer(std::shared_ptr<Player> pl) { _table->doAddPlayer(pl); }
  // static bool deletePlayer(int id) { _table->doDeletePlayer(id); }
  static void initialize() { _table->doInitialize(); }                                        // inicjalizuje stol - ustawia karty, tasuje
  static void endRound() { _table->doEndRound(); }                                            // konczy obecna runde
  static void giveFirstCards() { _table->doGiveFirstCards(); }                                // rozdaje pierwsze karty
  static void showPlayers() { _table->doShowPlayers(); }                                      // wyswietla graczy i ich wyniki(bez pierwszej karty krupiera)
  static void showFullPlayers() { _table->doShowFullPlayers(); }                              // wyswietla graczy i ich wyniki
  static void resetActive() { _table->doResetActive(); }                                      // resetuje aktywnego gracza
  static void nextPlayer() { _table->doNextPlayer(); }                                        // przechodzi do kolejnego gracza
  static void giveCard() { _table->doGiveCard(); }                                            // daje karte aktywnemu graczowi
  static std::list<std::shared_ptr<Player>>::iterator active() { return _table->doActive(); } // zwraca iterator aktywnego gracza
  static unsigned int size() { return _table->_players::size(); }                             // zwraca rozmiar stolu(ilosc graczy)
  static bool checkCards() { return _table->doCheckCards(); }                                 // sprawdza karty aktywnego gracza
  static bool checkBlackjack() { return _table->doCheckBlackjack(); }                         // sprwadza czy blackjack

private:
  Table() {}
  int _active;                          // aktywny gracz
  static std::unique_ptr<Table> _table; // obiekt stolu
  std::list<std::shared_ptr<Player>>::iterator doActive();
  void doAddPlayer(std::shared_ptr<Player> pl) { _players::push_back(pl); }
  // bool doDeletePlayer(int);
  void doInitialize();
  void doGiveFirstCards();
  void doShowPlayers();
  void doShowFullPlayers();
  void doResetActive() { _active = 0; }
  void doGiveCard();
  void doEndRound();
  void doNextPlayer();
  bool doCheckCards();
  bool doCheckBlackjack();
};

#endif