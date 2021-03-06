#include <card.h>
#include <iostream>

void Card::set(suit s, figure f) // setowanie karty
{
    _symbol = s;
    _value = f;
}

suit operator++(suit &s, int) // operator ++ dla enum suit
{
    suit ret = sAll[s];
    s = sAll[(s + 1) % 4];
    return ret;
}

figure operator++(figure &f, int) // operator ++ dla enum figure
{
    static int count = f;
    // std::cout << count << std::endl;
    figure ret = fAll[(count - 2) % 13];
    f = fAll[(count++ - 2) % 13];
    return ret;
}