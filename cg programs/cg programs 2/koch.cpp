#include<iostream>
//#include<conio.h>
#include<math.h>
#include<graphics.h>
using namespace std;

void koch(int x1,int y1,int x2,int y2,int it)
{
  float ang=60*M_PI/180;
  int x3=(2*x1+x2)/3;
  int y3=(2*y1+y2)/3;
  int x4=(x1+2*x2)/3;
  int y4=(y1+2*y2)/3;

  int x=x3+(x4-x3)*cos(ang)+(y4-y3)*sin(ang);
  int y=y3-(x4-x3)*sin(ang)+(y4-y3)*cos(ang);

  if(it>0)
  {
    koch(x1,y1,x3,y3,it-1);
    koch(x3,y3,x,y,it-1);
    koch(x,y,x4,y4,it-1);
    koch(x4,y4,x2,y2,it-1);
  }
  else
  {
    line(x1,y1,x3,y3);
    line(x3,y3,x,y);
    line(x,y,x4,y4);
    line(x4,y4,x2,y2);
    /*line(x3,y3,x1,y1);
    line(x,y,x3,y3);
    line(x4,y4,x,y);
    line(x2,y2,x4,y4);*/
  }
}

int main(void)
{
  int gd=DETECT,gm=VGAMAX;
  initgraph(&gd,&gm,"NULL");
  int x1=50,y1=200,x2=400,y2=200;
  //settextstyle(1,0,1);
  //outtextxy(80,70,"KOCH CURVE");
  koch(x1,y1,x2,y2,1);
  //settextstyle(3,0,2);
  outtextxy(450,200,"1st iteration");
  koch(50,350,400,350,4);
  //outtextxy(450,350,"4th iteration");
  //koch(100,350,500,350,2);
  getch();
  return 0;
}
