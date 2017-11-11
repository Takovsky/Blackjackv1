#include <player.h>

bool Player::checkCards()
{
    if (sum() > 21)
    {
        for (auto pd = cBegin(); pd != cEnd(); pd++)
            if ((*pd)->value() == ace)
            {
                aceToOne(); // robimy jedynke z asa, jesli suma > 21
                break;
            }
        if (sum() < 20)
            return true;
        else
            return false;
    }
    else
        return true;
}