#include <graphics.h>
#ifndef PLANT_H
#define PLANT_H

class Plant
{
protected:
    int x, y, width, height, life, types;

public:
    Plant(int _x = getmaxwidth(), int _y = getmaxheight(), int w = 1, int h = 1, int l = 1, int t = 0);

    virtual void setX(int value);
    virtual void setY(int value);
  
    int getType();
    void setWidth(int value);
    void setHeight(int value);
    void setLife(int value);

    int getX();
    int getY();
    int getWidth();
    int getHeight();
    int getLife();

    virtual void draw() = 0;
    virtual void undraw() = 0;

    virtual void attack() = 0;

};



#endif