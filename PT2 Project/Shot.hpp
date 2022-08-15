#ifndef SHOT_H
#define SHOT_H

class Shot
{
    int x, y, radius, holdx;

public:
    Shot(int _x = 0, int _y = 0, int r = 15);

    void setX(int value);
    void holdX();
    void setY(int value);
    void setRadius(int value);

    int getX();
    int getY();
    int getRadius();

    void draw() const;
    void undraw() const;

    void move();
};


#endif