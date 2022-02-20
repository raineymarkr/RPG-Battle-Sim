#include "Combat.h"
#include "Monster.h"
#include "Character.h"
#include "Items.h"


Combat::Combat(Monster& newM) : M(newM)
{
}

void Combat::combatMenu(Character& C)
{
    std::cout << std::endl;
	C.display();
	M.display();
	std::cout << "What do you do? 1 attack, 2 Use Magic, 3 Use Item, 4 Rest" << std::endl;
	std::cin >> choice;
	std::cout << std::endl;
	switch (choice)
	{
		case 1:
			C.attack(M);
			break;

		case 2:
		    std::cout << "Choose a spell to cast!\n\n1 Magic Missile: DMG\t2 Poison: DMG over Time\n3 Burn: -DEF\t4 Confuse: -ACC\n5 Slow: -SPD\t6 Weak: -ATK\n7: Heal" << std::endl;
            std::cin >> mchoice;
		    switch (mchoice)
		    {
            case 1:
                C.magicmissile(M);
                break;
            case 2:
                C.poison(M);
                break;
            case 3:
                C.burn(M);
                break;
            case 4:
                C.confuse(M);
                break;
            case 5:
                C.slow(M);
                break;
            case 6:
                C.weak(M);
                break;
            case 7:
                C.heal();
                break;
		    }

			break;
        case 3:

            std::cout << "Choose an item to use!\n\n1 Potion (+15 HP)\t 2 Magic Powder (+15 MP)" << std::endl;
            std::cin >> ichoice;


            if (ichoice == 1)
            {
                if(C.PotCon == 0)
                {
                    std::cout << "You've got no potions!\n" << std::endl;
                } else {
                C.PotCon -= 1;
                Items* item = new Items;
                item->Potion(C);
                delete item;
                break;
                }
            }

            if (ichoice == 2)
            {
                if(C.PowCon == 0)
                {
                    std::cout << "You're out of powder!" << std::endl;
                } else
                {
                C.PowCon -= 1;
                Items* item = new Items;
                item->MagicPowder(C);
                delete item;
                break;
                }
            }
            break;

        case 4:
            C.rest();
            break;
	}
}


void Combat::combat1(Character& C)
{

	while  (M.HP>=0 && C.HP>=0 )
	{
		if(M.Poisoned) M.HP -= 5;

		combatMenu(C);
        M.attack(C);

	}
	if (M.HP<1){
        printart("pics/trophy");
        std::cout << "Congratulations! You killed the monster!" << std::endl;
		std::cout << std::endl;}
		else if (C.HP<1){
                if (!C.revive)
                    {
                    printart("pics/grave");
                    std::cout << "You fell in battle. Game over." << std::endl;
                    C.alive = false;
                    } else
                    {
                        C.revive = false;
                        C.HP = C.HPMAX;
                        C.MP = C.MPMAX;
                    }
		std::cout << std::endl;}

}



