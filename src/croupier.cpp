#include <iostream>
#include <list>
#include <memory>
#include <stdio.h> //rand
#include <croupier.h>
#include <player.h>

void Croupier::doShuffle() // tassowanie kart
{
    for (int i = 0; i < _deck::size(); i++)
    {
        _deck::swap(i, rand() % _deck::size());
    }
}

void Croupier::doGiveCard(Person &p) // dajemy karte graczowi
{
    p.pushCard(std::move(_deck::back()));
    _deck::pop_back();
}

bool Croupier::doPlay(std::list<std::shared_ptr<Player>> players) // gra krupiera
{
    bool shouldtake = false;
    bool playerslost = true;
    for (auto pd = players.begin(); pd != players.end(); pd++)
    {
        if (Croupier::sum() < (*pd)->sum())
            shouldtake = true; // jesli jakis gracz ma wiecej niz krupier, to krupier powinien brac
        if ((*pd)->sum() < 21)
            playerslost = false; // jesli ma wiecej niz 21 lub oczko, to kruppier nie ma sensu grac
    }
    if (shouldtake && !playerslost && Croupier::sum() < 17) // moze grac tylko jesli ma mniej kart niz 17
    {
        Croupier::takeCard();
        return Croupier::play(players);
    }
    else if (Croupier::sum() >= 17 && Croupier::sum() <= 21) // jesli ma 17-21
        return true;
    else if (Croupier::sum() > 21) // jesli ma powyzej
    {
        for (auto pd = Croupier::ccBegin(); pd != Croupier::ccEnd(); pd++)
        {
            if ((*pd)->value() == ace) // szukamy asa
            {
                _crp->aceToOne();
                break;
            }
        }
        if (Croupier::sum() > 21)
            return false; // i zwracamy co wyszlo
        else
            Croupier::play(players);
    }
}