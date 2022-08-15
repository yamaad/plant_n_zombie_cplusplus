#include "Zombie.hpp"
#include <graphics.h>
#include <cstdlib>
#include <ctime>

Zombie::Zombie(int _x, int _y, int w, int h, int _dx, int l) : x(_x), y(_y), width(w), height(h), dx(_dx), life(l)
{

    saveImage();
}
Zombie::~Zombie()
{
}

void Zombie::saveImage()
{
    int size = imagesize(x, y, x + width, y + height);
    image = new char[size];
    readimagefile("zombie.jpg", x, y, x + width, y + height);
    getimage(x, y, x + width, y + height, image);
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    bar(x, y, x + width, y + height);
}

void Zombie::setX(int value)
{
    x = value;
}
void Zombie::setY(int value) { y = value; }
void Zombie::setWidth(int value) { width = value; }
void Zombie::setHeight(int value) { height = value; }
void Zombie::setDx(int value) { dx = value; }
void Zombie::setLife(int value) { life -= value; }

int Zombie::getX()
{
    if (&x)
        return x;
}
int Zombie::getY()
{

    return y;
}
int Zombie::getWidth()
{
    return width;
}
int Zombie::getHeight()
{
    return height;
}
int Zombie::getDx()
{
    return dx;
}
int Zombie::getLife()
{
    return life;
}

void Zombie::draw() const
{
    if(x && y && image)
    putimage(x, y, image, COPY_PUT);
}

void Zombie::undraw() const
{

    setcolor(BLACK);

    setfillstyle(SOLID_FILL, BLACK);
    bar(x, y, x + width + width * 0.5, y + height);
}
void Zombie::zombieStep()
{
    if (life < 0)
    {
        undraw();
        return;
    }
    undraw();

    draw();

    x -= dx;
    
    
}
