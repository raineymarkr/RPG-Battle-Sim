#include "Monster.h"
#include <cmath>


Monster::Monster(std::string newname, int newATK, int newDEF, int newSPD, int newACC)
{
    Name = newname;
    HP = newDEF * 10;
    ATK = newATK;
    DEF = newDEF;
    SPD = newSPD;
    ACC = newACC;
}

void Monster::attack( Character& target)
{
        DiceRoller* die = new DiceRoller;
        DodgePer = target.SPD * 4;
        DiceRoll = die->rollDie();

        if (DodgePer >= DiceRoll)
        {
            Damage = abs(ATK - target.DEF) * 1.3;
            if(Damage < 0)
                Damage = 0;
            else{
            target.HP -= Damage;
            std::cout << Name << " attacks " << target.Name << " for " << Damage << " damage!" << std::endl;
            std::cout << std::endl;}
        } else
        {
            std::cout << Name << " attacks " << target.Name << " but they dodged!" << std::endl;
            std::cout << std::endl;
        }
        delete die;


    }

        void Monster::display()
        {
            std::cout << Name << " HP : " << HP << std::endl;
        }
