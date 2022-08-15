#include "Plant.hpp"
#include "Zombie.hpp"
#include <graphics.h>

#ifndef ZOMBIEEATER_H
#define ZOMBIEEATER_H

class ZombieEater : public Plant
{

public:
    ZombieEater(int _x = getmaxwidth(), int _y = getmaxheight(), int w = 98, int h = 122, int l = 1000, int t = 2);

    void setX(int value);
    void setY(int value);

    void draw();
    void undraw();

    void attack();
};

#endif