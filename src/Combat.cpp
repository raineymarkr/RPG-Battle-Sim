#include "Combat.h"
#include "Monster.h"
#include "Character.h"

Combat::Combat(Monster& newM) : M(newM)
{
}

void Combat::combatMenu(Character& C)
{
    std::cout << std::endl;
	C.display();
	M.display();
	std::cout << "What do you do? 1 attack, 2 Use Magic, 3 Rest" << std::endl;
	int choice;
	int mchoice;
	std::cin >> choice;
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
		    }

			break;
        case 3:
            C.rest();
            break;
	}
}


void Combat::combat1(Character& C)
{

	while  (M.HP>0 && C.HP>0 )
	{
        if(C.poisoned) M.HP -= 5;

		M.attack(C);

		combatMenu(C);

	}
	if (M.HP<0)
        std::cout << "Congratulations! You killed the monster!" << std::endl;
		std::cout << std::endl;

	if (C.HP<0)
    	std::cout << "You fell in battle. Game over." << std::endl;
		std::cout << std::endl;

}



