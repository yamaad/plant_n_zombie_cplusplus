#include "Plant.hpp"
#include <graphics.h>

Plant::Plant(int _x, int _y, int w, int h, int l, int t) : x(_x), y(_y), width(w), height(h), life(l), types(t)
{
}
void Plant::setX(int value) { x = value; }
void Plant::setY(int value) { y = value; }

int Plant::getType() { return types; }

void Plant::setWidth(int value) { width = value; }
void Plant::setHeight(int value) { height = value; }
void Plant::setLife(int value) { life -= value; }

int Plant::getX()
{
    return x;
}
int Plant::getY()
{
    return y;
}
int Plant::getWidth()
{
    return width;
}
int Plant::getHeight()
{
    return height;
}
int Plant::getLife()
{
    return life;
}
