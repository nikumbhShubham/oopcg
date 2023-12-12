#include <iostream>
#include <graphics.h>

const int INSIDE = 0; // Bit code for the inside region of a rectangle
const int LEFT = 1;   // Bit code for the left region of a rectangle
const int RIGHT = 2;  // Bit code for the right region of a rectangle
const int BOTTOM = 4; // Bit code for the bottom region of a rectangle
const int TOP = 8;    // Bit code for the top region of a rectangle

const int xMax = 400; // Define the maximum x-coordinate of the window
const int yMax = 300; // Define the maximum y-coordinate of the window
const int xMin = 100; // Define the minimum x-coordinate of the window
const int yMin = 100; // Define the minimum y-coordinate of the window

int computeOutCode(int x, int y) {
    int code = INSIDE;

    if (x < xMin)       // to the left of rectangle
        code |= LEFT;
    else if (x > xMax)  // to the right of rectangle
        code |= RIGHT;
    if (y < yMin)       // below the rectangle
        code |= BOTTOM;
    else if (y > yMax)  // above the rectangle
        code |= TOP;

    return code;
}

void cohenSutherland(int x1, int y1, int x2, int y2) {
    int outcode1 = computeOutCode(x1, y1);
    int outcode2 = computeOutCode(x2, y2);
    bool accept = false;

    while (true) {
        if (!(outcode1 | outcode2)) { // Both points inside window
            accept = true;
            break;
        } else if (outcode1 & outcode2) { // Both points outside window, trivially reject
            break;
        } else {
            int x, y;
            int outcodeOut = outcode1 ? outcode1 : outcode2;

            if (outcodeOut & TOP) { // Point is above the clip window
                x = x1 + (x2 - x1) * (yMax - y1) / (y2 - y1);
                y = yMax;
            } else if (outcodeOut & BOTTOM) { // Point is below the clip window
                x = x1 + (x2 - x1) * (yMin - y1) / (y2 - y1);
                y = yMin;
            } else if (outcodeOut & RIGHT) { // Point is to the right of clip window
                y = y1 + (y2 - y1) * (xMax - x1) / (x2 - x1);
                x = xMax;
            } else { // Point is to the left of clip window
                y = y1 + (y2 - y1) * (xMin - x1) / (x2 - x1);
                x = xMin;
            }

            if (outcodeOut == outcode1) {
                x1 = x;
                y1 = y;
                outcode1 = computeOutCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                outcode2 = computeOutCode(x2, y2);
            }
        }
    }

    if (accept) {
        // Draw the clipped line
        setcolor(RED);
        line(x1, y1, x2, y2);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Drawing the clipping window
    rectangle(xMin, yMin, xMax, yMax);

    // Coordinates of the line
    int x1 = 50, y1 = 80, x2 = 450, y2 = 350;

    // Drawing the original line
    setcolor(GREEN);
    line(x1, y1, x2, y2);

    // Applying Cohen-Sutherland line clipping algorithm
    cohenSutherland(x1, y1, x2, y2);

    delay(15000);
    closegraph();
    return 0;
}
