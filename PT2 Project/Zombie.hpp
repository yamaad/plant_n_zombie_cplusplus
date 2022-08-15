#include <graphics.h>
#ifndef ZOMBIE_H
#define ZOMBIE_H

class Zombie
{
    int x, y, width, height, dx, life;
    int level;
    void *image;
    

public:
    Zombie(int _x = getmaxwidth() / 1.1, int _y = getmaxheight() * 0.5, int w = 76, int h = 122, int _dx = 20, int l = 1000);

    void saveImage();
    ~Zombie();
    void setX(int value);
    void setY(int value);
    void setWidth(int value);
    void setHeight(int value);
    void setDx(int value);
    void setLife(int value);

    int getX();
    int getY();
    int getWidth();
    int getHeight();
    int getDx();
    int getLife();

    void draw() const;
    void undraw() const;
    void zombieStep();
};

#endif