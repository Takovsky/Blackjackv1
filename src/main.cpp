#include <iostream>
#include <memory>  // smart ptr
#include <stdio.h> // rand
#include <time.h>  // time
#include <card.h>
#include <croupier.h>
#include <deck.h>
#include <player.h>

std::unique_ptr<Croupier> Croupier::_crp;
unsigned int Player::_count = 0;

int main()
{
    std::srand(time(0));
    Player p;
    Player p2;
    Croupier::getInstance();
    Croupier::setDeck();
    Croupier::shuffle();
    Croupier::giveCard(p);
    // for (auto pd = a.begin(); pd != a.end(); pd++)
        // std::cout << (*pd)->value() << std::endl;
        // std::cout << p.name() << "\t" << p.id() << std::endl;
        // std::cout << p2.name() << "\t" << p2.id() << std::endl;
    }