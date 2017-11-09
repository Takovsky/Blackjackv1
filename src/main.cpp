#include <iostream>
#include <memory>  // smart ptr
#include <stdio.h> // rand
#include <time.h>  // time
#include <card.h>
#include <croupier.h>
#include <deck.h>
#include <player.h>
#include <table.h>

using namespace std;

unique_ptr<Table> Table::_table;
unique_ptr<Croupier> Croupier::_crp;
unsigned int Player::_count = 0;

int main()
{
    srand(time(NULL));
    Table::getInstance();
    Table::initialize();
    list<shared_ptr<Player>> pllist;
    pllist.push_back(make_shared<Player>("adamek"));
    pllist.push_back(make_shared<Player>("ziutek"));
    pllist.push_back(make_shared<Player>("frajerek"));
    for (auto &d : pllist)
        Table::addPlayer(d);
    Table::giveFirstCards();
    for (auto &d : pllist)
        std::cout << d->id() << ". " << d->name() << "\t" << d->sum() << std::endl;
    Table::showPlayers();
}