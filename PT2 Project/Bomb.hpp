#include "Plant.hpp"
#include <graphics.h>

#ifndef BOMB_H
#define BOMB_H

class Bomb : public Plant
{
public:
    Bomb(int _x = getmaxwidth(), int _y = getmaxheight(), int w = 98, int h = 122, int l = 1, int t = 3);

    void setX(int value);
    void setY(int value);

    int getX();
    int getY();
    void draw();
    void undraw();

    void attack();
};

#endif