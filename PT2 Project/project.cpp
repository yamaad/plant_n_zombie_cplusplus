#include "Zombie.hpp"
#include "Plant.hpp"
#include "PeaShoter.hpp"
#include "Shot.hpp"
#include "Bomb.hpp"
#include "ZombieEater.hpp"
#include "Spot.hpp"
#include "PlantBar.hpp"
#include <graphics.h>
#include <cstdlib>
#include <ctime>

Spot spots[9] =
    {Spot(getmaxwidth() * 0.02, getmaxheight() / 4), Spot(getmaxwidth() * 0.15, getmaxheight() / 4), Spot(getmaxwidth() * 0.3, getmaxheight() / 4),
     Spot(getmaxwidth() * 0.02, getmaxheight() / 2), Spot(getmaxwidth() * 0.15, getmaxheight() / 2), Spot(getmaxwidth() * 0.3, getmaxheight() / 2),
     Spot(getmaxwidth() * 0.02, getmaxheight() / 1.25), Spot(getmaxwidth() * 0.15, getmaxheight() / 1.25), Spot(getmaxwidth() * 0.3, getmaxheight() / 1.25)};

char *num[9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

void topBar();
void showSpots();
void choosePlant(int &index, Plant *plants[], int size);

int main()
{
    initwindow(getmaxwidth(), getmaxheight(), "plant vs zombie");

    int index = 0;
    int iteration = 0;
    int helper = 0;
    int score = 0;

    Plant *plants[9];
    for (int i = 0; i < 9; i++)
    {
        plants[i] = NULL;
    }

    Zombie *zombies[30];
    for (int i = 0; i < 30; i++)
    {
        srand(time(0));
        int random = rand() % 100;
        helper += 100;
        zombies[i] = new Zombie;
        if (i >= 0 && i < 10)
        {
            if (helper == 1000)
                helper == 0;
            zombies[i]->setX(getmaxwidth() + helper);
            zombies[i]->setY(getmaxheight() / 4);
        }
        if (i > 10 && i < 20)
        {
            if (helper == 1000)
                helper == 0;
            zombies[i]->setX(getmaxwidth() + helper);
            zombies[i]->setY(getmaxheight() / 2);
        }
        if (i > 20 && i < 30)
        {
            if (helper == 1000)
                helper == 0;
            zombies[i]->setX(getmaxwidth() + helper);
            zombies[i]->setY(getmaxheight() / 1.25);
        }
    }

    while (1)
    {
        topBar();
        showSpots();
        choosePlant(index, plants, 9);

        for (int i = 0; i < 30; i++)
        {
            if (zombies[i])
            {
                zombies[i]->zombieStep();
                for (int j = 0; j < 9; j++)
                {
                    if (plants[j] && plants[j]->getType() == 2 && zombies[i]->getX() < plants[j]->getX() && zombies[i]->getY() == plants[j]->getY())
                    {
                        plants[j]->attack();
                        plants[j]->undraw();
                        delete plants[j];
                        zombies[i]->setLife(1000);
                        zombies[i]->zombieStep();
                        delete zombies[i];
                        score += 1;
                    }

                    if (plants[j] && plants[j]->getType() == 3 && zombies[i]->getX() < plants[j]->getX() && zombies[i]->getY() == plants[j]->getY())
                    {
                        plants[j]->attack();
                        plants[j]->undraw();
                        delete plants[j];
                        zombies[i]->setLife(1000);
                        zombies[i]->zombieStep();
                        delete zombies[i];
                        score += 1;
                    }
                    if (plants[j] && plants[j]->getType() == 1)
                    //  {
                     plants[j]->attack();
                    // if (zombies[i]->getX() < plants[j]->getX() + plants[j]->getWidth())
                    // {
                    // plants[j]->undraw();
                    // delete plants[j];
                    // }
                     
                    
                    // if (plants[j]->getShotPos() > zombies[i]->getX())
                    // {
                    // zombies[i]->setLife(25);
                    // plants[j]->resetShot();
                    // }
                    // if (zombies[i]->getLife() < 1)
                    // {
                    // zombies[i]->undraw();
                    //
                    // delete zombies[i];
                    // }
                    // }
                }
            }
            if (zombies[i])
            {
                if (zombies[i]->getX() < 0 && zombies[i]->getY() != NULL)
                    goto gameover;
            }
        }
    }
gameover:
    setcolor(RED);
    outtextxy(getmaxwidth() / 2, getmaxheight() / 2, "GAME OVER!!");
    getch();
    closegraph();
}

void topBar()
{
    PlantBar bar(getmaxwidth() / 2.5, 0, getmaxwidth() / 2.5 + 60, 100);
    bar.drawBar();
}

void showSpots()
{
    for (int i = 0; i < 9; i++)
    {
        spots[i].drawSpotNum(num[i]);
    }
}

void choosePlant(int &index, Plant *plants[], int size)
{

    char ch;
    //kbhit();
    if (kbhit())
    {
        ch = getch();
        ch = toupper(ch);

        switch (ch)
        {
        case 'C':
            for (int i = 0; i < 9; i++)
            {
                if (plants[i] == NULL)
                {
                    plants[i] = new Bomb;
                    index = i;
                    i = 9;
                }
            }
            break;

        case 'X':
            for (int i = 0; i < 9; i++)
            {
                if (plants[i] == NULL)
                {
                    plants[i] = new ZombieEater;
                    index = i;
                    i = 9;
                }
            }
            break;

        case 'Z':
            for (int i = 0; i < 9; i++)
            {
                if (plants[i] == NULL)
                {
                    plants[i] = new PeaShoter;
                    index = i;
                    i = 9;
                }
            }
            break;

        case '1':
            plants[index]->setX(spots[0].getX());
            plants[index]->setY(spots[0].getY());
            plants[index]->draw();
            break;

        case '2':
            plants[index]->setX(spots[1].getX());
            plants[index]->setY(spots[1].getY());
            plants[index]->draw();
            break;

        case '3':
            plants[index]->setX(spots[2].getX());
            plants[index]->setY(spots[2].getY());
            plants[index]->draw();
            break;

        case '4':
            plants[index]->setX(spots[3].getX());
            plants[index]->setY(spots[3].getY());
            plants[index]->draw();
            break;

        case '5':
            plants[index]->setX(spots[4].getX());
            plants[index]->setY(spots[4].getY());
            plants[index]->draw();
            break;

        case '6':
            plants[index]->setX(spots[5].getX());
            plants[index]->setY(spots[5].getY());
            plants[index]->draw();
            break;

        case '7':
            plants[index]->setX(spots[6].getX());
            plants[index]->setY(spots[6].getY());
            plants[index]->draw();
            break;

        case '8':
            plants[index]->setX(spots[7].getX());
            plants[index]->setY(spots[7].getY());
            plants[index]->draw();
            break;

        case '9':
            plants[index]->setX(spots[8].getX());
            plants[index]->setY(spots[8].getY());
            plants[index]->draw();
            break;
        }
    }
}
