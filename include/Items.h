#ifndef ITEMS_H
#define ITEMS_H

#include "Character.h"
#include <vector>

class Items
{
    public:
        Items();


        void Potion(Character& C);
        void MagicPowder(Character& C);
        void HPUP(Character& C);
        void MPUP(Character& C);
        void ATKUP(Character& C);
        void DEFUP(Character& C);
        void ACCUP(Character& C);
        void SPDUP(Character& C);
        void INTUP(Character& C);
        void WISUP(Character& C);
        void Revive(Character& C);
};

#endif // ITEMS_H
