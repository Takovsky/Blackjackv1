#include <table.h>
#include <player.h>
#include <croupier.h>

void Table::doAddPlayer(std::string name)
{
    _players::push_back(std::shared_ptr<Player>(new Player(name)));
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
    for (auto &pl : _players())
        pl->clearCards();
    Croupier::clearTable();
}