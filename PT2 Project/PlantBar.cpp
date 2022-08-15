#include "PlantBar.hpp"
#include <graphics.h>

PlantBar::PlantBar(int _x, int _y, int w, int h) : x(_x), y(_y), width(w), height(h) {}

void PlantBar::drawBar()
{
    readimagefile("PeaShoter.jpg", x, y, width, height);
    readimagefile("ZombieEater.jpg", width, y, width + 60, height);
    readimagefile("bomb.jpg", width + 60, y, width + 120, height);

    setcolor(RED);

    outtextxy(x + 30, y + height, "Z");
    outtextxy(width + 30, y + height, "X");
    outtextxy(width + 90, y + height, "c");
}