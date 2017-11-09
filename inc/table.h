#ifndef _TABLE_H
#define _TABLE_H

#include <list>
#include <memory>
#include <player.h>
#include <croupier.h>

class Table : private std::list<std::shared_ptr<Player>>
{
  private:
    typedef std::list<std::shared_ptr<Player>> _players;

  public:
    ~Table() { _table.release(); }
    static bool getInstance()
    {
        if (!_table)
        {
            _table = std::unique_ptr<Table>(new Table);
            return true;
        }
        else
            return false;
    }
    static void addPlayer(std::string name) { _table->doAddPlayer(name); }
    static bool deletePlayer(int id) { _table->doDeletePlayer(id); }
    static void initialize() { _table->doInitialize(); }
    static void newRound() { _table->doNewRound(); }

  private:
    Table() {}
    static std::unique_ptr<Table> _table;
    void doAddPlayer(std::string);
    bool doDeletePlayer(int);
    void doInitialize();
    void doNewRound();
};

#endif