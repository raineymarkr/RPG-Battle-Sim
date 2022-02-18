#include <iostream>
#include <string>
#include "DiceRoller.h"
#include "Character.h"
#include "Combat.h"
#include "printart.h"

//Define Monsters
Monster Slime("Slime", 5, 8, 3, 9);
Monster Skeleton("Skeleton", 10, 6, 10, 8);
Monster Demon("Demon", 15, 8, 15, 10);

//Define Stat Sheet Variables
std::string Name;
int ATK;
int DEF;
int SPD;
int ACC;
int WIS;
int INT;

int choice, mlist;

int main()
{
    srand(time(0));
    bool ifMenu = true;

    while(ifMenu){
    std::cout << "1. Design a Character\n2. Choose an Enemy and Fight!\n3. Helpful Info\n0. End" << std::endl;
    std::cin >> choice;
    if( choice == 1) {
    std::cout << "What is your character's Name?" << std::endl;
    std::cin >> Name;

    std::cout << "What is your character's ATK?" << std::endl;
    std::cin >> ATK;

    std::cout << "What is your character's DEF?" << std::endl;
    std::cin >> DEF;

    std::cout << "What is your character's ACC?" << std::endl;
    std::cin >> ACC;

    std::cout << "What is your character's SPD?" << std::endl;
    std::cin >> SPD;

    std::cout << "What is your character's INT?" << std::endl;
    std::cin >> INT;

    std::cout << "What is your character's WIS?" << std::endl;
    std::cin >> WIS;
    std::cout << std::endl;


    }else if(choice == 2){
            std::cout << "\nChoose an Enemy" << std::endl;
            std::cout << "1. Slime, 2. Skeleton, 3. Demon\n";
            std::cin >> mlist;
            if(mlist == 1){
            std::cout << "\n----- BATTLE START! -----\n\n";
            printart("monsters/slime");
            Character Player(Name, ATK, DEF, SPD, ACC, WIS, INT);
            Player.poisoned = false;
            Combat combat(Slime);
            combat.combat1(Player);

            std::cout << "You've conquered!" << std::endl;}
            else if(mlist == 2){
            std::cout << "\n----- BATTLE START! -----\n";
            printart("monsters/skeleton");
            Character Player(Name, ATK, DEF, SPD, ACC, WIS, INT);
            Player.poisoned = false;
            Combat combat(Skeleton);
            combat.combat1(Player);

            std::cout << "You've conquered!" << std::endl;}
            else if(mlist == 3){
            std::cout << "\n----- BATTLE START! -----\n";
            printart("monsters/demon");
            Character Player(Name, ATK, DEF, SPD, ACC, WIS, INT);
            Player.poisoned = false;
            Combat combat(Demon);
            combat.combat1(Player);

            std::cout << "You've conquered!" << std::endl;}
            }
            else if(choice == 3){
                std::cout << "-------------------\nHelpful Info:\n\nIts best to limit your character to roughly 40-50 stat points, total.\nATK  Increase Attack Damage.\nDEF  Increase HP and Decrease Damage Taken.\nACC  Increase Attack Hit Chance. \nINT  Increase Magic Damage.\nWIS  Increase MP and Increase Spell Hit Chance." << std::endl;
                std::cout << "\nSome suggested Builds are:\n\tFighter     Warrior     Adept       Wizard\nATK:\t10          12          3           3\nDEF:\t8           12          5           7"<< std::endl;
                std::cout << "ACC:\t12          8           7           7\nSPD:\t12          8           5           7\nINT:\t3           3           9           12\nWIS:\t3           3           9           12\n" << std::endl;
            }
            else if(choice == 0){
            return 0;}
            }
}

