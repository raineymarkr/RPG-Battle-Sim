#include <iostream>
#include <string>
#include "DiceRoller.h"
#include "Character.h"
#include "Combat.h"
#include "Items.h"
#include "printart.h"

//Define Monsters
Monster Slime("Slime", 8, 6, 3, 10);
Monster Skeleton("Skeleton", 10, 6, 10, 8);
Monster Demon("Demon", 13, 8, 15, 10);

//Define Stat Sheet Variables
std::string Name;
int ATK;
int DEF;
int SPD;
int ACC;
int WIS;
int INT;


const int MAXPT = 40;
int PTotal;

int choice, mlist, ichoice;

void createChar();

int main()
{
    srand(time(0));
    bool ifMenu = true;

    std::cout << "\nSome suggested Builds are:\n\tFighter     Warrior     Adept       Wizard\nATK:\t8           10          0           0\nDEF:\t8           10          5           5"<< std::endl;
    std::cout << "ACC:\t10          8           7           7\nSPD:\t10          8           5           7\nINT:\t0           0           9           12\nWIS:\t0           0           9           12\n" << std::endl;

    std::cout << "What is your character's Name?" << std::endl;
    std::cin >> Name;

    std::cout << "Assign 40 or fewer stat points. 0 is permitted. \n" << std::endl;
    std::cout << "What is your character's ATK?" << std::endl;
    std::cin >> ATK;
    PTotal += ATK;

    std::cout << "What is your character's DEF?" << std::endl;
    std::cin >> DEF;
    PTotal += DEF;

    std::cout << "What is your character's ACC?" << std::endl;
    std::cin >> ACC;
    PTotal += ACC;

    std::cout << "What is your character's SPD?" << std::endl;
    std::cin >> SPD;
    PTotal += SPD;

    std::cout << "What is your character's INT?" << std::endl;
    std::cin >> INT;
    PTotal += INT;

    std::cout << "What is your character's WIS?" << std::endl;
    std::cin >> WIS;
    PTotal += WIS;
    Character Player(Name, ATK, DEF, SPD, ACC, WIS, INT);

    if (MAXPT < PTotal)
    {
        std::cout << "You've over-powered your character!\n\n" << std::endl;
    } else{ std::cout << std::endl;}

    while(ifMenu){
    std::cout << "1. Choose an Enemy and Fight!\n2. Shop\n3. Heal\n4. Helpful Info\n5.Re-Do Character\n0. End" << std::endl;
    std::cin >> choice;
    if( choice == 1) {
            std::cout << "\nChoose an Enemy" << std::endl;
            std::cout << "1. Slime, 2. Skeleton, 3. Demon\n";
            std::cin >> mlist;
            if(mlist == 1){
            std::cout << "\n----- BATTLE START! -----\n\n";
            printart("monsters/slime");

            Slime.Poisoned = false;
            Combat combat(Slime);
            combat.combat1(Player);
            Slime.HP = Slime.DEF * 10;
            if(Player.alive = true)
            {
            std::cout << Player.Name << " receives a 10 Gold Bounty for their service.\n\n" << std::endl;
            Player.Gold += 10;
            } else {createChar();}

            }
            else if(mlist == 2){
            std::cout << "\n----- BATTLE START! -----\n";
            printart("monsters/skeleton");
            Skeleton.Poisoned = false;
            Combat combat(Skeleton);
            combat.combat1(Player);
            Skeleton.HP = Skeleton.DEF * 10;
            if(Player.alive = true)
            {
            Player.Gold += 25;
            std::cout << Player.Name << " receives a 25 Gold Bounty for their service.\n\n" << std::endl;
            } else {createChar();}
            }
            else if(mlist == 3){
            std::cout << "\n----- BATTLE START! -----\n";
            printart("monsters/demon");
            Demon.Poisoned = false;
            Combat combat(Demon);
            combat.combat1(Player);
            Demon.HP = Demon.DEF * 10;
            if(Player.alive = true)
            {
            Player.Gold += 50;
            std::cout << Player.Name << " receives a 50 Gold Bounty for their service.\n\n" <<  std::endl;
            } else {createChar();}
            }
        }

            else if(choice == 2)
            {
            std::cout << "You enter a ragged hut, situated deep within the swamps and found only with \ntrusted knowledge. Inside, an old woman sits by a fire burning brightly but \nemanating not from combusting wood but pure nothingness.\n\nShe reveals her wares:\n" << std::endl;
            std::cout << "Gold: "<< Player.Gold << std::endl;
            std::cout << "1 Potion (10 Gold, +15 HP)\t2 Magic Powder (10 Gold, +15 MP)\n3 Yellow Potion (25 Gold, ATK Up)\t4 Purple Potion (25 Gold, DEF Up)\n5 Green Potion (25 Gold, ACC Up)\t6 White Potion (25 Gold, SPD Up) \n7: Strange Book (25 Gold, INT up)\t8. Blue Mushrooms (25 Gold, WIS Up)\n9. HP Up (25 Gold, +5 Max HP)\t10. MP Up(25 Gold, +5 Max MP)\n11.Phoenix Feather (30 Gold, Revive when Killed)\n0. Leave" << std::endl;
            std::cin >> ichoice;
            if(ichoice == 1)
            {
                if(Player.Gold < 10)
            {
                std::cout << "You are broke. Go earn money." << std::endl;
            } else
            {
                Player.PotCon += 1;
                std::cout << "You place a Potion into your bag.\n" << std::endl;
                Player.Gold -=10;
            }

            } else if(ichoice == 2)
            {
                if(Player.Gold < 10)
            {
                std::cout << "You are broke. Go earn money." << std::endl;
            } else
            {
                Player.PotCon += 1;
                std::cout << "You fill a small leather bag with powder.\n" << std::endl;
                Player.Gold -=10;
            }
            }else if (ichoice == 3)
            {
            if(Player.Gold < 25)
            {
                std::cout << "You are broke. Go earn money." << std::endl;
            } else
            {
                Items* item = new Items;
                item->ATKUP(Player);
                delete item;
                Player.Gold -=25;
            }
            }else if (ichoice == 4)
                {
            if(Player.Gold < 25)
            {
                std::cout << "You are broke. Go earn money." << std::endl;
            } else
            {
                Items* item = new Items;
                item->DEFUP(Player);
                delete item;
                Player.Gold -=25;
            }
            }else if (ichoice == 5)
                {
            if(Player.Gold < 25)
            {
                std::cout << "You are broke. Go earn money." << std::endl;
            } else
            {
                Items* item = new Items;
                item->ACCUP(Player);
                delete item;
                Player.Gold -=25;

                }
                }else if (ichoice == 6)
                {
            if(Player.Gold < 25)
            {
                std::cout << "You are broke. Go earn money." << std::endl;
            } else
            {
                Items* item = new Items;
                item->SPDUP(Player);
                delete item;
                Player.Gold -=25;
            }
            }else if(ichoice == 7)
                {
            if(Player.Gold < 25)
            {
                std::cout << "You are broke. Go earn money." << std::endl;
            } else
            {
                Items* item = new Items;
                item->INTUP(Player);
                delete item;
                Player.Gold -=25;
            }
            }else if(ichoice == 8)
                {
            if(Player.Gold < 25)
            {
                std::cout << "You are broke. Go earn money." << std::endl;
            } else
            {
                Items* item = new Items;
                item->WISUP(Player);
                delete item;
                Player.Gold -=25;
                }
                }else if(ichoice == 9)
                {
            if(Player.Gold < 25)
            {
                std::cout << "You are broke. Go earn money." << std::endl;
            } else
            {
                Items* item = new Items;
                item->HPUP(Player);
                delete item;
                Player.Gold -=25;
                }
                }else if(ichoice == 10)
            {
            if(Player.Gold < 25)
            {
                std::cout << "You are broke. Go earn money." << std::endl;
            } else
            {
                Items* item = new Items;
                item->MPUP(Player);
                delete item;
                Player.Gold -=25;
                }
            }else if(ichoice == 11)
                {
                if(Player.Gold < 30)
                    {
                    std::cout << "You are broke. Go earn money." << std::endl;
                    }
                else
                    {
                    Player.revive = true;
                    Player.Gold -=25;
                    }
                }

            }
            else if(choice == 3)
            {
                Player.HP = Player.HPMAX;
                std::cout<<Player.Name << " has their health restored.\n\n" << std::endl;
            }
            else if(choice == 4)
            {
                std::cout << "-------------------\nHelpful Info:\n\nIts best to limit your character to roughly 40-45 stat points, total.\nATK  Increase Attack Damage.\nDEF  Increase HP and Decrease Damage Taken.\nACC  Increase Attack Hit Chance. \nINT  Increase Magic Damage.\nWIS  Increase MP and Increase Spell Hit Chance." << std::endl;
                std::cout << "\nSome suggested Builds are:\n\tFighter     Warrior     Adept       Wizard\nATK:\t8           12          3           3\nDEF:\t8           12          5           5"<< std::endl;
                std::cout << "ACC:\t12          8           7           7\nSPD:\t12          8           5           7\nINT:\t3           3           9           12\nWIS:\t3           3           9           12\n" << std::endl;
            }
            else if(choice == 0)
            {return 0;}
            }
}

void createChar()
{
    std::cout << "\nSome suggested Builds are:\n\tFighter     Warrior     Adept       Wizard\nATK:\t8           12          0           0\nDEF:\t8           12          5           5"<< std::endl;
    std::cout << "ACC:\t12          8           7           7\nSPD:\t12          8           5           7\nINT:\t0           0           9           12\nWIS:\t0           0           9           12\n" << std::endl;

    std::cout << "What is your character's Name?" << std::endl;
    std::cin >> Name;

    std::cout << "Assign 40 or fewer stat points. 0 is permitted. \n" << std::endl;
    std::cout << "What is your character's ATK?" << std::endl;
    std::cin >> ATK;
    PTotal += ATK;

    std::cout << "What is your character's DEF?" << std::endl;
    std::cin >> DEF;
    PTotal += DEF;

    std::cout << "What is your character's ACC?" << std::endl;
    std::cin >> ACC;
    PTotal += ACC;

    std::cout << "What is your character's SPD?" << std::endl;
    std::cin >> SPD;
    PTotal += SPD;

    std::cout << "What is your character's INT?" << std::endl;
    std::cin >> INT;
    PTotal += INT;

    std::cout << "What is your character's WIS?" << std::endl;
    std::cin >> WIS;
    PTotal += WIS;
    Character Player(Name, ATK, DEF, SPD, ACC, WIS, INT);

    if (MAXPT < PTotal)
    {
        std::cout << "You've over-powered your character!\n\n" << std::endl;
    } else{ std::cout << std::endl;}
}

