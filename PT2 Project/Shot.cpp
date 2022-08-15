#include "Shot.hpp"
#include <graphics.h>



Shot::Shot(int _x, int _y, int r) : x(_x), y(_y), radius(r), holdx(x) {}

void Shot::setX(int value) { x = holdx = value; }
void Shot::holdX(){x = holdx;}
void Shot::setY(int value) { y = value; }
void Shot::setRadius(int value) { radius = value; }

int Shot::getX() { return x; }
int Shot::getY() { return y; }
int Shot::getRadius() { return radius; }

void Shot::draw() const
{
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    fillellipse(x, y, radius, radius);

    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    fillellipse(x - radius * 0.6, y - radius * 0.6, radius * 0.05, radius * 0.05);
}
void Shot::undraw() const
{
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    fillellipse(x, y, radius, radius);
}

void Shot::move()
{
    
    undraw();
    x += 40;

    draw();
}