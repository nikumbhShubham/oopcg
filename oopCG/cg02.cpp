#include <iostream>
#include <graphics.h>
using namespace std;
const int INSIDE = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int BOTTOM = 4;
const int TOP = 8;

const int xMin = 100;
const int yMin = 100;
const int yMax = 300;
const int xMax = 400;

int computeOutCode(int x, int y)
{
    int code = INSIDE;

    if (x < xMin)
    {
        code |= LEFT;
    }
    else if (x > xMax)
    {
        code |= RIGHT;
    }
    if (y < yMin)
    {
        code |= BOTTOM;
    }
    else if (y > yMax)
    {
        code |= TOP;
    }

    return code;
}

void cohenSutherland(int x1, int y1, int x2, int y2)
{
    int outcode1 = computeOutCode(x1, y1);
    int outcode2 = computeOutCode(x2, y2);
    bool accept = false;

    while (true)
    {
        if (!(outcode1 | outcode2))
        {
            accept = true;
            break;
        }
        else if (outcode1 & outcode2)
        {
            break;
        }
        else
        {
            int x, y;
            int outcodeOut = outcode1 ? outcode1 : outcode2;
            if (outcodeOut & TOP)
            {
                x = x1 + (x2 - x1) * (yMax - y1) / (y2 - y1);
                y = yMax;
            }
            else if (outcodeOut & BOTTOM)
            {
                x = x1 + (x2 - x1) * (yMin - y1) / (y2 - y1);
                y = yMin;
            }
            else if (outcodeOut & RIGHT)
            {
                y = y1 + (y2 - y1) * (xMax - x1) / (x2 - x1);
                x = xMax;
            }
            else
            {
                y = y1 + (y2 - y1) * (xMin - x1) / (x2 - x1);
                x = xMin;
            }
            if (outcodeOut == outcode1)
            {
                x1 = x;
                y1 = y;
                outcode1 = computeOutCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                outcode2 = computeOutCode(x2, y2);
            }
        }
    }
    if (accept)
    {
        setcolor(RED);
        line(x1, y1, x2, y2);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    rectangle(xMin, yMin, xMax, yMax);

    int x1 = 50, y1 = 80, x2 = 450, y2 = 350;
    setcolor(GREEN);
    line(x1, y1, x2, y2);

    cohenSutherland(x1, y1, x2, y2);
    delay(15000);
    getch();
    closegraph();

    return 0;
}