#ifndef _CROUPIER_H
#define _CROUPIER_H

#include <stdio.h>

class croupier
{
  public:
    bool getInstance()
    {
        if (crp == NULL)
        {
            crp = new croupier;
            return true
        }
        else
            return false
    }
  private:
    croupier *crp;
    croupier() {}
    ~croupier() {}
};

#endif