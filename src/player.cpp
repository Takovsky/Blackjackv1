#include <iostream>
#include <player.h>

bool Player::checkCards()
{
    if (sum() > 21)
    {
        int i = 0;
        for (auto pd = cBegin() + _aceplace; pd != cEnd(); pd++)
        {
            i++;
            if ((*pd)->value() == ace)
            {
                _aceplace = i;
                std::cout <<std::endl<< "Ace's value is now 1" << std::endl;
                aceToOne(); // robimy jedynke z asa, jesli suma > 21
                break;
            }
        }
        if (sum() < 20)
            return true;
        else
            return false;
    }
    else
        return true;
}