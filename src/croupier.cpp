#include <croupier.h>
#include <stdio.h> //rand

void Croupier::doShuffle(Deck &d)
{
    for (int i = 0; i < d.size(); i++)
    {
        d.swap(i, rand() % d.size());
    }
}