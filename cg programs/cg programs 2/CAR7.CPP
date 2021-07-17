#include<stdio.h>
#include<graphics.h>
//#include<dos.h>
using namespace std;
class Car
{
public:
void circle1(int );
void line1(int );
void arc1(int );
};
void Car::circle1(int i)
{
circle(130+i,170,30);
circle(260+i,170,30);
}
void Car::line1(int i)
{
line(160+i,170,230+i,170);  //line between circle
line(60+i,170,100+i,170);   //f line
line(60+i,100,120+i,100);   //up line
line(280+i,100,350+i,100);  //up2 line
line(290+i,170,350+i,170);  //b line
line(60+i,170,60+i,100);    //f s line
}

void Car::arc1(int i)
{
arc(200+i,100,,180,80);
arc(350+i,135,270,90,36);
//arc(120,135,180,90,36);
}
int main()
{
int i,j;
int gd=DETECT,gm=VGAMAX;
initgraph(&gd,&gd,NULL);
//outtextxy(150,150,"aissms");
Car c;
for(i=0;i<getmaxx();i++)
{
cleardevice();
c.circle1(i);
c.line1(i);
c.arc1(i);
delay(5);
}
getch();
closegraph();
return 0;
}
