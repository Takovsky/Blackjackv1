#ifndef _PERSON_H
#define _PERSON_H

#include <vector> // vector
#include <memory> // unique_ptr
#include <card.h>

// klasa osoby, bedaca podstawa do gracza i krupiera
class Person : private std::vector<std::unique_ptr<Card>>
{
private:
  typedef std::vector<std::unique_ptr<Card>> _cards; // vector kart danej osoby

public:
  void aceToOne() { _sum -= 10; }             // metoda zmieniajaca wartosc asa z 11 na 1
  int id() const { return _id; };             // metoda zwracajaca id osoby
  std::string name() const { return _name; }; // metoda zwracajaca nazwe osoby
  virtual ~Person() {}                        // destruktor wirtualny
  void pushCard(std::unique_ptr<Card> c)      // wrzucamy osobie karte na vector
  {                                           //
    _sum += c->value();                       //
    _cards::push_back(std::move(c));          //
  }                                           //
  void clearCards()                           // usuwany wszystkie karty z vectora osoby
  {
    _cards::clear();
    _sum = 0;
  }
  std::vector<std::unique_ptr<Card>>::iterator cBegin() { return _cards::begin(); } // iterator poczatku kart
  std::vector<std::unique_ptr<Card>>::iterator cEnd() { return _cards::end(); }     // iterator konca kart

protected:
  Person(int id, std::string name) : _id(id), _name(name), _sum(0) {} // konstruktor
  int _id;                                                            // id osoby
  std::string _name;                                                  // nazwa osoby
  unsigned int _sum;                                                  // suma punktow
};

#endif