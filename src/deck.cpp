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
    for (int i = 0; i < DECK_SIZE; i++) // tworzymy 52 karty
        push_back(std::unique_ptr<Card>(new Card));
    for (auto pd = begin(); pd != end(); pd++)
    {
        (*pd)->set(s++, f++); // kazda karta musi byc inna
    }
}

void Deck::swap(int a, int b) // zamiana dwoch kart ze soba
{
    Card tmp = *(*this)[a];
    *(*this)[a] = *(*this)[b];
    *(*this)[b] = tmp;
}