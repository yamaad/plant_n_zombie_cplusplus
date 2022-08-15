#include "Plant.hpp"
#include "Bomb.hpp"
#include <graphics.h>

Bomb::Bomb(int _x, int _y, int w, int h, int l, int t) : Plant(_x, _y, w, h, l, t) {}

void Bomb::setX(int value) { x = value; }
void Bomb::setY(int value) { y = value; }

int Bomb::getX() { return x; }
int Bomb::getY() { return y; }
void Bomb::draw()
{
    readimagefile("bomb.jpg", x, y, x + width, y + height);
}
void Bomb::undraw()
{
    setcolor(BLACK);

    setfillstyle(SOLID_FILL, BLACK);
    bar(x, y, x + width, y + height);
}

void Bomb::attack()
{
    undraw();

    readimagefile("explosion.jpg", x, y, x + width, y + height);

    // delay(1000);

     undraw();
}