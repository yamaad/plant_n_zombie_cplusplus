#include "Plant.hpp"
#include "Shot.hpp"
#include <graphics.h>

#ifndef PEASHOTER_H
#define PEASHOTER_H

class PeaShoter : public Plant
{

    Shot shot;

public:
    PeaShoter(int _x = getmaxwidth(), int _y = getmaxheight(), int w = 98, int h = 122, int l = 1000, int t = 1);

    void setX(int value);
    void setY(int value);

    void setShotPos();
    int getShotPos();
    void resetShot();
    void draw();
    void undraw();
    void attack();

};

#endif