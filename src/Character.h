#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include<iostream>
#include "Monster.h"
#include "main.h"
#include "DiceRoller.h"


class Character
{
    public:

        std::string Name;
        int HP;
        int MP;
        int ATK;
        int DEF;
        int ACC;
        int SPD;
        int INT;
        int WIS;
        int Damage;
        double DodgePer;
        int DiceRoll;
        int Heal;
        int Restore;

        bool poisoned;


        Character(std::string newname, int newATK, int newDEF, int newSPD, int newACC, int newWIS, int newINT);
        void display();
        void attack(Monster& target);
        void magicmissile(Monster& target);
        void poison(Monster& target);
        void slow(Monster& target);
        void burn(Monster& target);
        void confuse(Monster& target);
        void weak(Monster& target);
        void heal();
        void rest();

};

#endif // CHARACTER_H
