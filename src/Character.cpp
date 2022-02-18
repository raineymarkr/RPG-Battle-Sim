#include "Character.h"


Character::Character(std::string newname, int newATK, int newDEF, int newSPD, int newACC, int newWIS, int newINT)
{
    Name = newname;
    HP = newDEF * 5;
    MP = newWIS * 5;
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
        if(MP >= 5){
        MP -= 5;
        DiceRoller* die = new DiceRoller;
        DodgePer = WIS * 5;
        DiceRoll = die->rollDie();
        if(poisoned == true)
        {
            std::cout << Name << " opens their mouth wide as a dense, violet fog billows from their chest and fills the air.\nBut, the enemy was already poisoned!" << std::endl;
        }
        else if (DodgePer <= DiceRoll)
        {
            std::cout << Name << " opens their mouth wide, expecting a cloud to emerge, but nothing happens..." << std::endl;
        } else{
            std::cout << Name << " opens their mouth wide as a dense, violet fog billows from their chest and fills the air.\nEnemy poisoned!" << std::endl;
            poisoned = true;
            }
        } else rest();
}

void Character::burn( Monster& target)
{
        if(MP >= 5){
        MP -= 5;
        DiceRoller* die = new DiceRoller;
        DodgePer = WIS * 5;
        DiceRoll = die->rollDie();

        if (target.DEF <= 5)
        {
            std::cout << Name << " performs several hand signs, with each a burning trail grows stronger from an ember to an inferno that engulfs " << target.Name << ".\nBut, the enemy can't be burned any worse!"<< std::endl;

        } else if (DodgePer <= DiceRoll)
        {
            std::cout << Name << " performs several hand signs, but nothing happens..." << std::endl;
        }
        else{
            std::cout << Name << " performs several hand signs, with each a burning trail grows stronger from an ember to an inferno that engulfs " << target.Name << ".\nBurned!"<< std::endl;
        target.DEF -= 5;}
        } else rest();
}

void Character::confuse( Monster& target)
{
        if(MP >= 5){
        MP -= 5;
        DiceRoller* die = new DiceRoller;
        DodgePer = WIS * 5;
        DiceRoll = die->rollDie();

        if (target.ACC <= 5)
        {
            std::cout << Name << " performs a slow, mythical dance that begins to hypnotize " << target.Name << ".\nBut, the enemy can't be confused any more than it already is!"<< std::endl;

        } else if (DodgePer <= DiceRoll)
        {
            std::cout << Name << " begins to dance, but nothing happens..." << std::endl;
        }
        else{
            std::cout << Name << " performs a slow, mythical dance that begins to hypnotize" << target.Name << ".\nConfused!"<< std::endl;
        target.ACC -= 5;}
        } else rest();
}

void Character::slow( Monster& target)
{
        if(MP >= 5){
        MP -= 5;
        DiceRoller* die = new DiceRoller;
        DodgePer = WIS * 5;
        DiceRoll = die->rollDie();

        if (target.SPD <= 5)
        {
            std::cout << Name << " raises their arm to their chest and grips their fist tightly, summoning several glowing chains which dance around it. With a fist pump, the chains launch at the feet of " << target.Name << ".\nBut, the enemy can't be slowed any more!"<< std::endl;

        } else if (DodgePer <= DiceRoll)
        {
            std::cout << Name << " grips their fist dramatically, but nothing happens..." << std::endl;
        }
        else{
            std::cout << Name << " raises their arm to their chest and grips their fist tightly, summoning several glowing chains which dance around it. With a fist pump, the chains launch at the feet of " << target.Name << ".\nSlowed!"<< std::endl;
        target.SPD -= 5;}
        } else rest();
}

void Character::weak( Monster& target)
{

        if(MP >= 5){
        MP -= 5;
        DiceRoller* die = new DiceRoller;
        DodgePer = WIS * 5;
        DiceRoll = die->rollDie();

        if (target.ATK <= 5)
        {
            std::cout << Name << " chants a dark hymn, but "<< target.Name << "is already hysterically terrified. " << std::endl;

        } else if (DodgePer <= DiceRoll)
        {
            std::cout << Name << " chants a dark hymn, but nothing happens..." << std::endl;
        }
        else{
            std::cout << Name << " chants a dark hymn. " << target.Name << " begins to grow hysterical as the demonic tune penetrates their psyche.\nWeakened!"<< std::endl;
        target.DEF -= 5;}
        } else rest();
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
    int tempMax = DEF * 5;
    if (HP >= tempMax)
        {
            std::cout << "HP is maximized!" << std::endl;
        } else if(MP >= 5)
        {MP -= 5;
        DiceRoller* die = new DiceRoller;
        DiceRoll = die->rollDie();
        delete die;
        Heal = (DiceRoll%10 + WIS);
        HP += Heal;
        std::cout << Name << " mutters a silent prayer, enticing a dim but golden glow to radiate from their body.\n" << "HP healed by " << Heal << std::endl;
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
            std::cout << Name << " conjures an orb between their palms, feeding it magical energy until it glows like the hot sun. They launch it at " << target.Name << " but it dodges!" << std::endl;
        } else
        {
            Damage = (INT - target.DEF) * 1.5;
            target.HP -= Damage;
            std::cout << Name << " conjures an orb between their palms, feeding it magical energy until it glows like the hot sun. They launch it at " << target.Name << " for " << Damage << " damage!" << std::endl;

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



