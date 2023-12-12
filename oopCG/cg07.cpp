#include <iostream>
#include <graphics.h>

class Ball
{
public:
    virtual void draw() = 0;
    virtual void move() = 0;
    virtual ~Ball(){};
};
class smallBall : public Ball
{
private:
    int x, y, Radius, dx, dy;
    int color;
public:
    smallBall(int xstart, int ystart, int startRadius, int startDx, int startDy, int ballColor)
    {
        x= xstart;
        y = ystart;
        Radius = startRadius;
        dx = startDx;
        dy = startDy;
        color = ballColor;
    }
    void draw() override
    {
        setcolor(color);
        circle(x, y, Radius);
        floodfill(x, y, color);
    }
    void move()override
    {

        x += dx;
        y += dy;

        if ((x + Radius >= getmaxx()) || (x - Radius <= 0))
        {
            dx = -dx;
        }
        if ((y + Radius >= getmaxy()) || (y - Radius <= 0))
        {
            dy = -dy;
        }
    }
};

using namespace std;
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    smallBall sb(50, 50, 20, 2, 3, RED);

    while (!kbhit())
    {
        cleardevice();
        sb.move();
        sb.draw();

        delay(20);
    }

    closegraph();

    return 0;
}