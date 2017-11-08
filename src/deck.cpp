#include <vector>
#include <memory>
#include <deck.h>
#include <card.h>
#include <iostream>

using std::make_shared;
using std::shared_ptr;
using std::vector;

void Deck::set()
{
    suit s = diamond;
    figure f = two;
    for (int i = 0; i < DECK_SIZE; i++)
        push_back(std::unique_ptr<Card>(new Card));
    for (auto pd = begin(); pd != end(); pd++)
    {
        (*pd)->set(s++, f++);
    }
}

void Deck::swap(int a, int b)
{
    Card tmp = *(*this)[a];
    *(*this)[a] = *(*this)[b];
    *(*this)[b] = tmp;
}