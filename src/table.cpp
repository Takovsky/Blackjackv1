#include <iostream>
#include <list>   // list
#include <memory> // smart ptr
#include <table.h>
#include <player.h>
#include <croupier.h>

// bool Table::doDeletePlayer(int id)
// {
//     if (_players::empty())
//         return false;
//     else
//     {
//         for (auto pd = _players::begin(); pd != _players::end(); pd++)
//             if ((*pd)->id() == id)
//             {
//                 _players::erase(--pd, ++pd);
//                 return true;
//             }
//     }
//     return false;
// }

void Table::doInitialize() // inicjalizuje stol
{
    Croupier::setDeck(); // ustawia tale kart
    Croupier::shuffle(); // tasuje je
}

void Table::doGiveFirstCards() // rozdaje kazdemu po 2 pierwsze karty
{
    for (int i = 0; i < 2; i++)
    {
        Croupier::takeCard();
        for (auto pd = _players::begin(); pd != _players::end(); pd++)
            Croupier::giveCard(**pd);
    }
}

void Table::doShowPlayers() // wyswietla graczy
{
    std::cout << std::endl
              << "0. "
              << "Croupier's score = " << Croupier::sum() - Croupier::firstCard() << std::endl;
    for (auto pd = _players::begin(); pd != _players::end(); pd++)
        std::cout << (*pd)->id() + 1 << ". " << (*pd)->name() << "'s score = " << (*pd)->sum() << std::endl;
    std::cout << std::endl;
}

void Table::doShowFullPlayers() // wyswietla graczy
{
    std::cout << std::endl
              << "0. "
              << "Croupier's score = " << Croupier::sum() << std::endl;
    for (auto pd = _players::begin(); pd != _players::end(); pd++)
        std::cout << (*pd)->id() + 1 << ". " << (*pd)->name() << "'s score = " << (*pd)->sum() << std::endl;
    std::cout << std::endl;
}

void Table::doGiveCard() // daje karte aktywnemu graczowi
{
    auto it = _players::begin();
    for (int i = 0; i < _active; i++)
        it++;
    Croupier::giveCard(**it);
}

std::list<std::shared_ptr<Player>>::iterator Table::doActive() // zwraca iterator do aktywnego gracza
{
    auto it = _players::begin();
    for (int i = 0; i < _active; i++)
        it++;
    return it;
}

void Table::doNextPlayer() // gracz++
{
    if (_active < _players::size())
        _active++;
}

void Table::doEndRound() // konczy runde
{
    int smax = 0;
    std::list<std::shared_ptr<Player>> winners;        // lista zwyceizcow
    std::cout << "Croupier plays now..." << std::endl; //
    bool crpin = Croupier::play(_players(*this));      // tura krupiera
    if (crpin)                                         // jesli suma kart krupiera <= 21
        smax = Croupier::sum();                        // maxymalna suma to suma krupiera
    for (auto pd = _players::begin(); pd != _players::end(); pd++)
    {
        if ((*pd)->checkCards() && smax < (*pd)->sum())
            smax = (*pd)->sum(); // jesli jakis gracz ma wiecej punktow, to nadpisujemy
    }
    for (auto pd = _players::begin(); pd != _players::end(); pd++)
    {
        if (smax == (*pd)->sum())   // jesli max punktow sie powtarza, to wszystkich graczy
            winners.push_back(*pd); // z tyloma punktami wpisujemy na liste zwyceizcow
    }
    _table->doShowFullPlayers();      // wyswietlamy graczy
    if (winners.empty() && crpin) // jesli wygral krupier
    {
        std::cout << "Croupier won with score " << Croupier::sum() << std::endl;
    }
    else if (winners.empty() && !crpin) // jesli nikt nie wygral
        std::cout << "No winners this round" << std::endl;
    else // jesli wygral(i) gracz(e)
    {
        std::cout << "The winners are:" << std::endl;
        for (auto pd : winners)
            std::cout << pd->id() + 1 << ". " << pd->name() << " with score " << pd->sum() << std::endl;
    }
    for (auto pd = _players::begin(); pd != _players::end(); pd++)
        (*pd)->clearCards(); // czyscimy karty graczy
    Croupier::clearTable();  // i krupiera
}

bool Table::doCheckCards() // sprawdzanie czy gracz nadal w grze
{
    auto it = _players::begin();
    for (int i = 0; i < _active; i++)
        it++;
    return (*it)->checkCards();
}

bool Table::doCheckBlackjack() // sprawdzanie oczka
{
    auto it = _players::begin();
    for (int i = 0; i < _active; i++)
        it++;
    return (*it)->checkBlackjack();
}