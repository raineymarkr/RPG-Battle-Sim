#include "Character.h"


Character::Character(std::string newname, int newATK, int newDEF, int newSPD, int newACC, int newWIS, int newINT)
{
    Name = newname;
    HP = newDEF * 5;
    MP = newWIS * 10;
    ATK = newATK;
    DEF = newDEF;
    ACC = newACC;
    SPD = newSPD;
    WIS = newWIS;
    INT = newINT;

}

void Character::attack( Monster& target)
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

void Character::poison( Monster& target)
{
        DiceRoller* die = new DiceRoller;
        DodgePer = WIS * 5;
        DiceRoll = die->rollDie();
        if (DodgePer <= DiceRoll)
        {
            std::cout << Name << "opens their mouth wide, expecting a cloud to emerge, but nothing happens..." << std::endl;
        }
        else{
            std::cout << Name << " opens their mouth wide as a dense, violet fog billows from their chest and fills the air.\nPoisoned!" << std::endl;
            poisoned = true;
        }
}

void Character::burn( Monster& target)
{
        DiceRoller* die = new DiceRoller;
        DodgePer = WIS * 5;
        DiceRoll = die->rollDie();

        if (DodgePer <= DiceRoll)
        {
            std::cout << Name << " performs several hand signs, but nothing happens..." << std::endl;
        }
        else{
            std::cout << Name << " performs several hand signs, with each a burning trail grows stronger from an ember to an inferno that engulfs " << target.Name << "\nBurned!"<< std::endl;
        target.DEF -= 5;}
}

void Character::confuse( Monster& target)
{
        DiceRoller* die = new DiceRoller;
        DodgePer = WIS * 5;
        DiceRoll = die->rollDie();

        if (DodgePer <= DiceRoll)
        {
            std::cout << Name << " begins to dance, but nothing happens..." << std::endl;
        }
        else{
            std::cout << Name << " performs a slow, mythical dance that slowly hypnotizes " << target.Name << "\nConfused!"<< std::endl;
        target.ACC -= 5;}
}

void Character::slow( Monster& target)
{
        DiceRoller* die = new DiceRoller;
        DodgePer = WIS * 5;
        DiceRoll = die->rollDie();

        if (DodgePer <= DiceRoll)
        {
            std::cout << Name << " grips their fist dramatically, but nothing happens..." << std::endl;
        }
        else{
            std::cout << Name << " raises their arm to their chest and grips their fist tightly, summoning several glowing chains which dance around it. With a fist pump, the chains launch at the feet of " << target.Name << "\nSlowed!"<< std::endl;
        target.SPD -= 5;}
}

void Character::weak( Monster& target)
{
        DiceRoller* die = new DiceRoller;
        DodgePer = WIS * 5;
        DiceRoll = die->rollDie();

        if (DodgePer <= DiceRoll)
        {
            std::cout << Name << " chants a dark hymn, but nothing happens..." << std::endl;
        }
        else{
            std::cout << Name << " chants a dark hymn. " << target.Name << "begins to grow hysterical as the demonic tune penetrates their psyche. \nWeakened!"<< std::endl;
        target.DEF -= 5;}
}

void Character::rest()
{
        DiceRoller* die = new DiceRoller;
        DiceRoll = die->rollDie();
        delete die;
        Restore = (DiceRoll%5 + WIS);
        MP += Restore;
}

void Character::heal()
{
    if(MP >= 5){
        MP -= 5;
        DiceRoller* die = new DiceRoller;
        DiceRoll = die->rollDie();
        delete die;
        Heal = (DiceRoll%10 + WIS);
        HP += Heal;
    } else rest();
}

void Character::magicmissile(Monster& target)
{
    if(MP >= 5){
        MP -= 5;
        DiceRoller* die = new DiceRoller;
        DodgePer = ((WIS)/target.SPD);
        if(DodgePer < 0){DodgePer = 1;}
        DiceRoll = die->rollDie();
        if (DodgePer >= DiceRoll)
        {
            std::cout << Name << " conjures an orb and launches it at " << target.Name << " but it dodges!" << std::endl;
        } else
        {
            Damage = (INT - target.DEF) * 1.5;
            target.HP -= Damage;
            std::cout << Name << " conjures an orb and launches it at " << target.Name << " for " << Damage << " damage!" << std::endl;

        }
        delete die;
    } else {
        std::cout << "No MP! You rest!\n";
        rest();
            }
}

void Character::display()
        {
            std::cout << Name << " HP : " << HP << " MP: " << MP << std::endl;
        }



