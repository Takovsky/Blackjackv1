#include <table.h>
#include <player.h>
#include <croupier.h>
#include <iostream>

void Table::doAddPlayer(std::shared_ptr<Player> pl)
{
    _players::push_back(pl);
}

bool Table::doDeletePlayer(int id)
{
    if (_players::empty())
        return false;
    else
    {
        for (auto pd = _players::begin(); pd != _players::end(); pd++)
            if ((*pd)->id() == id)
            {
                _players::erase(--pd, ++pd);
                return true;
            }
    }
    return false;
}

void Table::doInitialize()
{
    if (!Croupier::getInstance())
        return;
    Croupier::setDeck();
    Croupier::shuffle();
}

void Table::doNewRound()
{
    for (auto pd = _players::begin(); pd != _players::end(); pd++)
        (*pd)->clearCards();
    Croupier::clearTable();
}

void Table::doGiveFirstCards()
{
    Croupier::takeCard();
    for (auto pd = _players::begin(); pd != _players::end(); pd++)
        Croupier::giveCard(**pd);
}

void Table::doShowPlayers()
{
    for (auto pd = _players::begin(); pd != _players::end(); pd++)
        std::cout << (*pd)->id() << ". " << (*pd)->name() << "\t" << (*pd)->sum() << std::endl;
}