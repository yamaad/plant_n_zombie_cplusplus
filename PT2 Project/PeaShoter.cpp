#include "PeaShoter.hpp"
#include "Shot.hpp"
#include <graphics.h>

PeaShoter::PeaShoter(int _x, int _y, int w, int h, int l, int t) : Plant(_x, _y, w, h, l, t)
{

    shot.setX(x + width + 15);
    shot.setY(y + (height / 3));
}

void PeaShoter::setX(int value)
{
    x = value;
    setShotPos();
}
void PeaShoter::setY(int value)
{
    y = value;
    setShotPos();
}

void PeaShoter::setShotPos()
{
    shot.setX(x + width + 15);
    shot.setY(y + (height / 3));
}

int PeaShoter::getShotPos()
{
    return shot.getX() + shot.getRadius();
}

void PeaShoter::resetShot()
{

    shot.holdX();
}
void PeaShoter::draw()
{
    readimagefile("Peashoter.jpg", x, y, x + width, y + height);
}

void PeaShoter::undraw()
{
    setcolor(BLACK);

    setfillstyle(SOLID_FILL, BLACK);
    bar(x, y, x + width, y + height);

    shot.undraw();
}
void PeaShoter::attack()
{

    if (life < 1)
    {
        undraw();

        return;
    }

    if (shot.getX() > getmaxwidth())
        resetShot();

    shot.move();

    
}