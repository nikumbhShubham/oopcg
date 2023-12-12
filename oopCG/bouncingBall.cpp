#include <iostream>
#include <graphics.h>

// Base class for Ball
class Ball {
public:
    virtual void draw() = 0; // Abstract method for drawing the ball
    virtual void move() = 0; // Abstract method for moving the ball
    virtual ~Ball() {} // Virtual destructor
};

// Derived class for Small Ball
class SmallBall : public Ball {
private:
    int x, y, radius;
    int dx, dy;
    int color;

public:
    SmallBall(int startX, int startY, int startRadius, int startDx, int startDy, int ballColor) {
        x = startX;
        y = startY;
        radius = startRadius;
        dx = startDx;
        dy = startDy;
        color = ballColor;
    }

    void draw() override {
        setcolor(color);
        circle(x, y, radius);
        floodfill(x, y, color);
    }

    void move() override {
        x += dx;
        y += dy;

        if ((x + radius >= getmaxx()) || (x - radius <= 0)) {
            dx = -dx;
        }

        if ((y + radius >= getmaxy()) || (y - radius <= 0)) {
            dy = -dy;
        }
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    SmallBall smallBall(50, 50, 20, 2, 3, RED);

    while (!kbhit()) {
        cleardevice();
        
        smallBall.move();
        smallBall.draw();

        delay(20);
    }

    closegraph();
    return 0;
}
