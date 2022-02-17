#include <iostream>
#include <string>
#include "DiceRoller.h"
#include "Character.h"
#include "Combat.h"

Monster Slime("Slime", 5, 10, 3, 9);
Monster Skeleton("Skeleton", 15, 6, 9, 8);
Monster Demon("Demon", 15, 8, 15, 10);


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
    std::cout << "1. Design a Character\n2. Choose an Enemy and Fight!\n0. End" << std::endl;
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


    }else if(choice == 2){
            std::cout << "Choose an Enemy" << std::endl;
            std::cout << "1. Slime, 2. Skeleton, 3. Demon\n";
            std::cin >> mlist;
            if(mlist == 1){
            Character Player(Name, ATK, DEF, SPD, ACC, WIS, INT);
            Combat combat(Slime);
            combat.combat1(Player);
            Player.poisoned = false;
            std::cout << "You conquered!" << std::endl;}
            else if(mlist == 2){
            Character Player(Name, ATK, DEF, SPD, ACC, WIS, INT);
            Combat combat(Skeleton);
            combat.combat1(Player);
            Player.poisoned = false;
            std::cout << "You conquered!" << std::endl;}
            else if(mlist == 3){
            Character Player(Name, ATK, DEF, SPD, ACC, WIS, INT);
            Combat combat(Demon);
            combat.combat1(Player);
            Player.poisoned = false;
            std::cout << "You conquered!" << std::endl;}
            }
            else if(choice == 0){
            return 0;}
            }
}

