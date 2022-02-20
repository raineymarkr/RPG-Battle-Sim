#ifndef MONSTER_H
#define MONSTER_H

#include "Character.h"
#include "DiceRoller.h"
#include "main.h"

class Monster
{
    public:
    std::string Name;
    int HP;
    int Damage;
    int ATK;
    int DEF;
    int SPD;
    int ACC;
    bool Poisoned;
    double DodgePer;
    int DiceRoll;
    std::string newname;
    int newHP, newDamage;



    Monster(std::string newname, int newATK, int newDEF, int newSPD, int newACC);

    void attack(Character&);
    void display();

};

#endif // MONSTER_H
