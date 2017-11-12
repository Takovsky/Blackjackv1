#include <iostream>
#include <memory>  // smart ptr
#include <stdio.h> // rand
#include <time.h>  // time
#include <croupier.h>
#include <player.h>
#include <table.h>

using namespace std;

unique_ptr<Table> Table::_table;     // inicjujemy zmienne statyczne klas
unique_ptr<Croupier> Croupier::_crp; //
unsigned int Player::_count = 0;     //

int main()
{
    srand(time(NULL));
    Table::getInstance();             // bierzemy instance stolu
    Croupier::getInstance();          // i krupiera
    char d = 'o';                     // char obslugujacy menu
    string name;                      // wczytywana nazwa gracza
    int players_nr;                   // ilosc graczy
    list<shared_ptr<Player>> players; // lista graczy
    cout << "Welcome to Blackack." << endl
         << "May the fortune be with you!" << endl
         << endl
         << "How many players are there?" << std::endl;
    cin >> players_nr;
    for (int i = 0; i < players_nr; i++)
    {
        cout << "Set " << i + 1 << ". player name: ";
        cin >> name;
        players.push_back(make_shared<Player>(name)); // wrzucamy graczy na liste
    }
    for (auto pd : players)
        Table::addPlayer(pd); // teraz z listy na stol
    while (d != 'q')
    {
        Table::initialize();     // inicjalizujemy rozgrywke
        Table::resetActive();    // resetujemy aktywnego gracza
        Table::giveFirstCards(); // rozdajemy kazdemu po 2 karty
        Table::showPlayers();    // wyswietlamy graczy
        for (int i = 0; i < Table::size(); i++)
        {
            d = 's';
            do
            {
                Table::checkCards();         // sprawdzamy czy moze >21, wtedy as = 1
                if (Table::checkBlackjack()) // sprawdzamy czy 21
                {
                    std::cout << std::endl
                              << "Blackjack is here! " << (*Table::active())->name() << " has scored 21!" << std::endl;
                    break;
                }
                cout << "It's " << (*Table::active())->name() << "'s turn" << std::endl
                     << "What you wish to do?(s - stand | h - hit)" << std::endl;
                cin >> d;
                if (d == 'h') // dajemy karty dopoki gracz podaje 'h' i jego suma <21
                {
                    Table::giveCard();                                    // dajemy karte jesli gracz wpisal h
                    if (!Table::checkCards() && !Table::checkBlackjack()) // sprawdzamy czy >21 i czy !blackjack
                    {
                        std::cout << "Sorry mate, unlucky one :(" << std::endl;
                        break;
                    }
                    else if (Table::checkBlackjack()) // sprawdzamy czy blackjack
                    {
                        std::cout << std::endl
                                  << "Blackjack is here! " << (*Table::active())->name() << " has scored 21!" << std::endl;
                        break;
                    }
                    Table::showPlayers(); // znowu wyswietlamy graczy
                }
            } while (d != 's');           // jesli wpiszemy s
            Table::showPlayers();         // to wyswietlamy graczy
            if (i == Table::size() - 1)   // (po drodze sprawdzamy czy to juz ostatni gracz)
                Table::showFullPlayers(); // (jesli tak to wyswietlamy obie karty krupiera)
            Table::nextPlayer();          // i przechodzimy do nastepnego gracza
        }
        Table::endRound(); // po ostatnim graczu i krupierze konczymy runde
        cout << "What u wish to do now?(n - new game | q - quit)" << endl;
        cin >> d;
    }
}
