#include "Items.h"


Items::Items()
{
}



void Items::Potion(Character& C)
{
    int tempMax = C.DEF * 5;
    if (C.HP <= tempMax)
        {
            std::cout << C.Name << " removes a bottle from their satchel and removes the cork. They throw it back, unimpressed with the taste." << std::endl;
            C.HP += 15;
        } else
        C.HP = tempMax;

}

void Items::MagicPowder(Character& C)
{
    int tempMax = C.WIS * 5;
    if (C.MP >= tempMax)
        {
            std::cout << C.Name << " opens a small leather pouch and pulls a small scoop of crystaline powder from within. They inhale it quickly, grimacing at the burn. \nMP is maximized!" << std::endl;
            C.MP += 15;
        } else
        C.MP = tempMax;

}

void Items::HPUP(Character& C)
{
    std::cout << C.Name << " grows healthier.\n+5 HP.\n" << std::endl;
    C.HP += 5;
    C.HPMAX += 5;
}

void Items::MPUP(Character& C)
{
    std::cout << C.Name << " glows with a dull blue aura.\n+5 MP.\n" << std::endl;
    C.MP += 5;
    C.MPMAX += 5;
}

void Items::ATKUP(Character& C)
{
    std::cout << C.Name << " feels their muscles bulge, growing stronger.\n+5 ATK.\n" <<std::endl;
    C.ATK += 5;
}

void Items::DEFUP(Character& C)
{
    std::cout << C.Name << "'s skin grows tougher, taking a noticably more leather-like texture.\n+5 DEF.\n" <<std::endl;
    C.DEF += 5;
}

void Items::ACCUP(Character& C)
{
    std::cout << C.Name << " begins to see things much more clearly, their focus becoming razor-sharp..\n+5 ACC.\n" <<std::endl;
    C.ACC += 5;
}

void Items::SPDUP(Character& C)
{
    std::cout << C.Name << " wanna go fast.\n+5 SPD.\n" <<std::endl;
    C.SPD += 5;
}

void Items::INTUP(Character& C)
{
    std::cout << C.Name << " has solved German Idealism.\n+5 INT.\n" <<std::endl;
    C.INT += 5;
}

void Items::WISUP(Character& C)
{
    std::cout << C.Name << " peers through their Ego, seeing the 12 dimensional web of inter-connectivity between nature and human.\n+5 WIS.\n" <<std::endl;
    C.WIS += 5;
}

void Items::Revive(Character& C)
{
    if (C.revive != true)
    {
        std::cout << C.Name << "places the delicate and warm feather of a Phoenix into their bag.\n" << std::endl;
        C.revive = true;
    } else
    std::cout << "You've already used a revive!" << std::endl;
}
