#include "Monster.h"
#include <cmath>

//Monster Constructor
Monster::Monster(std::string newname, int newATK, int newDEF, int newSPD, int newACC)
{
    Name = newname;
    HP = newDEF * 10;
    ATK = newATK;
    DEF = newDEF;
    SPD = newSPD;
    ACC = newACC;
}

//Basic Attack
void Monster::attack( Character& target)
{
        DiceRoller* die = new DiceRoller;
        DodgePer = target.SPD * 4;
        DiceRoll = die->rollDie();

        if (DodgePer <= DiceRoll)
        {
            Damage = (ATK - (target.DEF/1.9)) * 1.3;
            if(Damage < 1)
            {
              Damage = 0;
            }
            else if (ACC*2 > DiceRoll){
            std::cout << "Critical hit!" << std::endl;
            Damage = Damage*2;
            target.HP -= Damage;
            }else
            target.HP -= Damage;
            std::cout << Name << " attacks " << target.Name << " for " << Damage << " damage!" << std::endl;
            std::cout << std::endl;
        } else
        {
            std::cout << Name << " attacks " << target.Name << " but they dodged!" << std::endl;
            std::cout << std::endl;
        }
        delete die;


    }

        //Print Monster HP
        void Monster::display()
        {
            std::cout << Name << " HP : " << HP << std::endl;
        }
