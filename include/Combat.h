#ifndef COMBAT_H
#define COMBAT_H

#include "Character.h"
#include "Monster.h"
#include "printart.h"

class Combat
{
    public:
        Combat(Monster& C);

        Monster& M;

        void combatMenu(Character &C);
        void combat1(Character &C);

};

#endif // COMBAT_H
