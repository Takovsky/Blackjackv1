#ifndef _CROUPIER_H
#define _CROUPIER_H

#include <stdio.h>

class croupier
{
  public:
    bool getInstance()
    {
        if (_crp == NULL)
        {
            _crp = new croupier;
            return true;
        }
        else
            return false;
    }
  private:
    croupier *_crp;
    croupier() {}
    ~croupier() {}
};

#endif