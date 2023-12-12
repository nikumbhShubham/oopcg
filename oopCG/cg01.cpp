#include <graphics.h>
#include <iostream>
using namespace std;
void ffill(int x, int y, int oCol, int nCol)
{
    int current = getpixel(x, y);
    if (current == oCol)
    {
        delay(2);
        putpixel(x, y, nCol);
        ffill(x + 1, y, oCol, nCol);
        ffill(x - 1, y, oCol, nCol);
        ffill(x, y + 1, oCol, nCol);
        ffill(x, y - 1, oCol, nCol);
    }
}
int main()
{
    int x1, x2, y1, y2, x3, y3, xAvg, yAvg;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    cout<<"Enter the coordinates:\n";
    setcolor(1);
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    xAvg=(int)(x1+x2+x3)/3;
    yAvg=(int)(y1+y2+y3)/3;
    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x3,y3,x1,y1);


    ffill(xAvg,yAvg,BLACK,RED);
    return 0;
}