#include <graphics.h>

#ifndef PLANTBAR_H
#define PLANTBAR_H

class PlantBar
{
    int x, y, width, height;

public:

    PlantBar(int _x, int _y, int w, int h);

    void drawBar();
};

#endif