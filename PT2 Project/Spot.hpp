#include <graphics.h>

#ifndef SPOT_H
#define SPOT_H

class Spot
{
    int x;
    int y;

    public:

    Spot(int _x,int _y);
    
    void setX(int _x);
    void setY(int _y);

    int getX();
    int getY();

    void drawSpotNum(char* num);
    void undrawSpotNum(char* num);

};

#endif