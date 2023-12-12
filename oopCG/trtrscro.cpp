#include <iostream>
#include <graphics.h>
#include <math.h>

class Transform {
private:
    int m;
    int a[20][3];
    int c[20][3];

public:
    void accept();
    void operator*(float b[3][3]);
    void object();
};

void Transform::accept() {
    std::cout << "Enter the Number Of Edges: ";
    std::cin >> m;

    std::cout << "Enter The Coordinates:\n";
    for (int i = 0; i < m; i++) {
        std::cout << "Vertex " << i + 1 << ": ";
        for (int j = 0; j < 3; j++) {
            if (j >= 2) a[i][j] = 1;
            else std::cin >> a[i][j];
        }
    }
}

void Transform::operator*(float b[3][3]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            c[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                c[i][j] += (a[i][k] * b[k][j]);
            }
        }
    }
}

void Transform::object() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    line(300, 0, 300, 600);
    line(0, 300, 600, 300);

    for (int i = 0; i < m - 1; i++) {
        line(300 + a[i][0], 300 - a[i][1], 300 + a[i + 1][0], 300 - a[i + 1][1]);
    }
    line(300 + a[0][0], 300 - a[0][1], 300 + a[m - 1][0], 300 - a[m - 1][1]);

    for (int i = 0; i < m - 1; i++) {
        line(300 + c[i][0], 300 - c[i][1], 300 + c[i + 1][0], 300 - c[i + 1][1]);
    }
    line(300 + c[0][0], 300 - c[0][1], 300 + c[m - 1][0], 300 - c[m - 1][1]);

    int temp;
    std::cout << "Press 1 to continue: ";
    std::cin >> temp;
    closegraph();
}

int main() {
    int ch, tx, ty, sx, sy;
    float deg, theta, b[3][3];
    Transform t;
    t.accept();
    
    std::cout << "Enter your choice\n"
                 "1. Translation\n"
                 "2. Scaling\n"
                 "3. Rotation\n";
    std::cin >> ch;

    switch (ch) {
        case 1:
            std::cout << "TRANSLATION OPERATION\nEnter value for tx and ty: ";
            std::cin >> tx >> ty;
            b[0][0] = b[2][2] = b[1][1] = 1;
            b[0][1] = b[0][2] = b[1][0] = b[1][2] = 0;
            b[2][0] = tx;
            b[2][1] = ty;
            t * b;
            t.object();
            break;

        case 2:
            std::cout << "SCALING OPERATION\nEnter value for sx, sy: ";
            std::cin >> sx >> sy;
            b[0][0] = sx;
            b[1][1] = sy;
            b[0][1] = b[0][2] = b[1][0] = b[1][2] = 0;
            b[2][0] = b[2][1] = 0;
            b[2][2] = 1;
            t * b;
            t.object();
            break;

        case 3:
            std::cout << "ROTATION OPERATION\nEnter value for angle: ";
            std::cin >> deg;
            theta = deg * (3.14 / 100);
            b[0][0] = b[1][1] = cos(theta);
            b[0][1] = sin(theta);
            b[1][0] = sin(-theta);
            b[0][2] = b[1][2] = b[2][0] = b[2][1] = 0;
            b[2][2] = 1;
            t * b;
            t.object();
            break;

        default:
            std::cout << "Invalid choice";
            break;
    }

    getch();
    return 0;
}
