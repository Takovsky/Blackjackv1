#include <iostream>
#include <memory>  // smart ptr
#include <stdio.h> // rand
#include <time.h>  // time
#include <card.h>
#include <croupier.h>
#include <deck.h>

std::unique_ptr<Croupier> Croupier::_crp;

int main()
{
    std::srand(time(0));
    Deck a;
    a.set();
    Croupier::shuffle(a);
    for (auto pd = a.begin(); pd != a.end(); pd++)
        std::cout << (*pd)->value() << std::endl;
}