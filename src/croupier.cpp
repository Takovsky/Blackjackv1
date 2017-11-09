#include <croupier.h>
#include <stdio.h> //rand
#include <player.h>
#include <memory>
#include <iostream>

void Croupier::doShuffle()
{
    for (int i = 0; i < _deck::size(); i++)
    {
        _deck::swap(i, rand() % _deck::size());
    }
}

void Croupier::doGiveCard(Person &p)
{
    p.pushCard(std::move(_deck::back()));
    _deck::pop_back();
}