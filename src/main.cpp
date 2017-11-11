#include <iostream>
#include <memory>  // smart ptr
#include <stdio.h> // rand
#include <time.h>  // time
#include <croupier.h>
#include <player.h>
#include <table.h>

using namespace std;

unique_ptr<Table> Table::_table;
unique_ptr<Croupier> Croupier::_crp;
unsigned int Player::_count = 0;

int main()
{
    srand(time(NULL));
    Table::getInstance();
    Croupier::getInstance();
    char d = 'o';
    string name;
    int players_nr;
    list<shared_ptr<Player>> players;
    cout << "Welcome to Blackack." << endl
         << "May the fortune be with you!" << endl
         << endl
         << "How many players are there?" << std::endl;
    cin >> players_nr;
    for (int i = 0; i < players_nr; i++)
    {
        cout << "Set " << i + 1 << ". player name: ";
        cin >> name;
        players.push_back(make_shared<Player>(name));
    }
    for (auto pd : players)
        Table::addPlayer(pd);
    while (d != 'q')
    {
        Table::initialize();
        Table::resetActive();
        Table::giveFirstCards();
        Table::showPlayers();
        for (int i = 0; i < Table::size(); i++)
        {
            d = 's';
            do
            {
                if (!Table::checkCards())
                {
                    std::cout << "Sorry mate, unlucky one :(" << std::endl;
                    break;
                }
                else if (Table::checkBlackjack())
                {
                    std::cout << std::endl
                              << "Blackjack is here! " << (*Table::active())->name() << " has scored 21!" << std::endl;
                    break;
                }
                cout << "It's " << (*Table::active())->name() << "'s turn" << std::endl
                     << "What you wish to do?(s - stand | h - hit)" << std::endl;
                cin >> d;
                if (d == 'h')
                {
                    Table::giveCard();
                    if (!Table::checkCards())
                    {
                        std::cout << "Sorry mate, unlucky one :(" << std::endl;
                        break;
                    }
                    else if (Table::checkBlackjack())
                    {
                        std::cout << std::endl
                                  << "Blackjack is here! " << (*Table::active())->name() << " has scored 21!" << std::endl;
                        break;
                    }
                    Table::showPlayers();
                }
            } while (d != 's');
            Table::showPlayers();
            Table::nextPlayer();
        }
        Table::endRound();
        cout << "What u wish to do now?(n - new game | q - quit)" << endl;
        cin >> d;
    }
}
