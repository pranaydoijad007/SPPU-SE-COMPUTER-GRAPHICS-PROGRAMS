

#include<graphics.h>
#include<conio.h>
using namespace std;
void main()
{
 int gd=DETECT,gm=VGAMAX;
  float x,y;
 initgraph(&gd,&gm,"NULL");


 //y=getmaxy()/2;
 circle(100,100,50);
  circle(170,100,50);
   circle(240,100,50);

   circle(75,170,50);
 circle(145,170,50);
 circle(215,170,50);
 circle(285,170,50);

 getch();
 closegraph();

}
