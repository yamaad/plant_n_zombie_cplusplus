#include "Plant.hpp"
#include "Zombie.hpp"
#include "ZombieEater.hpp"
#include <graphics.h>

ZombieEater::ZombieEater(int _x, int _y, int w, int h, int l, int t) : Plant(_x, _y, w, h, l,t) {}

void ZombieEater::setX(int value) { x = value; }
void ZombieEater::setY(int value) { y = value; }

void ZombieEater::draw()
{
    readimagefile("zombieEater.jpg", x, y, x + width, y + height);
}
void ZombieEater::undraw()
{
    setcolor(BLACK);

    setfillstyle(SOLID_FILL, BLACK);
    bar(x, y, x + width, y + height);
}

void ZombieEater::attack()
{
    undraw();
    readimagefile("eating.jpg", x, y, x + width, y + height);
    // delay(100);
     draw();
}