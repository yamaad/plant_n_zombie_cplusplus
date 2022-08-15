#include "Spot.hpp"
#include <graphics.h>

Spot::Spot(int _x, int _y) : x(_x), y(_y) {}

void Spot::setX(int _x) { x = _x; }
void Spot::setY(int _y) { y = _y; }

int Spot::getX() { return x; }
int Spot::getY() { return y; }

void Spot::drawSpotNum(char *num)
{
    setcolor(RED);
    outtextxy(x, y, num);
}

void Spot::undrawSpotNum(char *num)
{
    setcolor(BLACK);
    outtextxy(x, y, num);
}