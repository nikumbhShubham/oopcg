#include <iostream>
#include <graphics.h>
using namespace std;

void drawCircle(int xCenter, int yCenter, int radius, int color)
{
    int x = 0, y = radius;
    int d = 3 - 2 * radius;

    while (x <= y)
    {
        putpixel(xCenter + x, yCenter + y, color);
        putpixel(xCenter - x, yCenter + y, color);
        putpixel(xCenter + x, yCenter - y, color);
        putpixel(xCenter - x, yCenter - y, color);
        putpixel(xCenter + y, yCenter + x, color);
        putpixel(xCenter - y, yCenter + x, color);
        putpixel(xCenter + y, yCenter - x, color);
        putpixel(xCenter - y, yCenter - x, color);
        if (d < 0)
        {
            d = d + 4 * x + 6;
        }
        else
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int xCenterBig, yCenterBig, radiusBig, xCenterSmall, yCenterSmall, radiusSmall;
    int x1, x2, x3, y1, y2, y3;
    cout << "Enter coordinates of the center of the big circle:\n";
    std::cout << "Enter the value of x: ";
    std::cin >> xCenterBig;
    std::cout << "Enter the value of y: ";
    std::cin >> yCenterBig;
    std::cout << "Enter the value of radius for the big circle: ";
    std::cin >> radiusBig;

    drawCircle(xCenterBig, yCenterBig, radiusBig, 15);

    std::cout << "Enter coordinates of the vertices of the triangle (inscribed within the circle):\n";
    std::cout << "Enter the value of x1: ";
    std::cin >> x1;
    std::cout << "Enter the value of y1: ";
    std::cin >> y1;
    std::cout << "Enter the value of x2: ";
    std::cin >> x2;
    std::cout << "Enter the value of y2: ";
    std::cin >> y2;
    std::cout << "Enter the value of x3: ";
    std::cin >> x3;
    std::cout << "Enter the value of y3: ";
    std::cin >> y3;

    setcolor(RED);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    std::cout << "Enter coordinates of the center of the small circle (inside the triangle):\n";
    std::cout << "Enter the value of x: ";
    std::cin >> xCenterSmall;
    std::cout << "Enter the value of y: ";
    std::cin >> yCenterSmall;
    std::cout << "Enter the value of radius for the small circle: ";
    std::cin >> radiusSmall;

    drawCircle(xCenterSmall,yCenterSmall,radiusSmall,4);

    getch();
    closegraph();

    return 0;
}