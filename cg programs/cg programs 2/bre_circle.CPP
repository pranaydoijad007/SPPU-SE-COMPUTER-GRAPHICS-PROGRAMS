#include<iostream>
#include<graphics.h>
using namespace std;
class pixel
{
  int x,y,x1,y1,r;
  float d;
  public:
    void get();
    void bre_cir();
    void disp();
};

void pixel::get()
{
  cout<<"\nEnter co-ordinates of circle: ";
  cin>>x;
  cin>>y;
  cout<<"\nEnter radius of circle: ";
  cin>>r;
}

void pixel::bre_cir()
{
  d=3-(2*r);
  x1=0;
  y1=r;
  do
  {
    if(d<=0)
    {
      d=d+(4*x1)+6;
    }
    else
    {
      d=d+4*(x1-y1)+10;
      y1=y1-1;
    }
    x1=x1+1;
    disp();
  }while(x1<=y1);
}

void pixel::disp()
{
  outtextxy(150,450,"Circle drawing using Bresenhams's Algorithm");
  putpixel(x1+x,y1+y,3);
  putpixel(x1+x,y-y1,3);
  putpixel(x-x1,y1+y,3);
  putpixel(x-x1,y-y1,3);
  putpixel(x+y1,y+x1,3);
  putpixel(x+y1,y-x1,3);
  putpixel(x-y1,y+x1,3);
  putpixel(x-y1,y-x1,3);
}

int main()
{
  int gd=DETECT,gm=VGAMAX;
  initgraph(&gd,&gm,NULL);
  pixel p;
  p.get();
  p.bre_cir();
  getch();
  closegraph();
}


