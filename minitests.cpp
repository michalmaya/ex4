#include "Players/Player.h"
#include "Players/Wizard.h"
#include "Players/Fighter.h"
#include "Players/Rogue.h"
int main()
{
    auto w = Wizard("Shay");
    std::cout << w << std::endl;
    w.damage(10);
    w.addCoins(5);
    std::cout << w.getAttackStrength() << std::endl;
    w.heal(2);
    std::cout << w << std::endl;
    return 0;
}
