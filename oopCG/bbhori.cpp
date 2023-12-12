#include <iostream>
#include <graphics.h>

class Ball {
private:
    int x, y, radius, dx; // dx: change in x direction
    int color;

public:
    Ball(int startX, int startY, int startRadius, int startDx, int ballColor) {
        x = startX;
        y = startY;
        radius = startRadius;
        dx = startDx;
        color = ballColor;
    }

    void draw() {
        setcolor(color);
        circle(x, y, radius);
        floodfill(x, y, color);
    }

    void move() {
        x += dx;

        if (x + radius >= getmaxx() || x - radius <= 0) {
            dx = -dx; // Change direction when ball reaches screen boundary
        }
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    Ball ball(50, 200, 20, 3, RED); // Start position, radius, speed, color

    while (!kbhit()) {
        cleardevice();
        
        ball.move();
        ball.draw();

        delay(20);
    }

    closegraph();
    return 0;
}
