#include <iostream>
#include <graphics.h>

class Ball {
public:
    virtual void draw() = 0;
    virtual void move() = 0;
    virtual ~Ball() {}
};

class VerticalBall : public Ball {
private:
    int x, y, radius;
    int dx, dy;
    int color;

public:
    VerticalBall(int startX, int startY, int startRadius, int startDx, int startDy, int ballColor) {
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
        y += dy;

        if ((y + radius >= getmaxy()) || (y - radius <= 0)) {
            dy = -dy;
        }
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    VerticalBall verticalBall(50, 50, 20, 0, 3, RED); // Vertical movement only

    while (!kbhit()) {
        cleardevice();
        
        verticalBall.move();
        verticalBall.draw();

        delay(20);
    }

    closegraph();
    return 0;
}
