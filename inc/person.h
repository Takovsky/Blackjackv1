#ifndef _PERSON_H
#define _PERSON_H

#include <vector>
#include <memory>
#include <card.h>

class Person : private std::vector<std::unique_ptr<Card>>
{
  private:
    typedef std::vector<std::unique_ptr<Card>> _cards;

  public:
    virtual int id() const { return _id; };
    virtual std::string name() const { return _name; };
    virtual ~Person() {}
    unsigned int sum() const { return _sum; }
    void pushCard(std::unique_ptr<Card> c)
    {
        _sum += c->value();
        _cards::push_back(std::move(c));
    }
    void clearCards()
    {
        _cards::clear();
        _sum = 0;
    }

  protected:
    Person(int id, std::string name) : _id(id), _name(name), _sum(0) {}
    int _id;
    std::string _name;
    unsigned int _sum;
};

#endif