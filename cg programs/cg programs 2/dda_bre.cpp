#include<iostream>
//#include<conio.h>
#include<graphics.h>
#include<stdlib.h>

using namespace std;
class dda
{
  public:
      float x1,y1,x2,y2,x,y,dx,dy,len;
      int i;
      float rux,ruy;
      void line1(int i);
      int sign(float k);
      void get();
};

void dda::get()
{
  cout<<"\nEnter starting co-ordinates: ";
  cout<<"\nX1: ";
  cin>>x1;
  cout<<"Y1: ";
  cin>>y1;
  cout<<"\nEnter end co-ordinates: ";
  cout<<"\nX2: ";
  cin>>x2;
  cout<<"\nY2: ";
  cin>>y2;
}
class bre:public dda
{
  public:
     void line1(int e);
};

void dda::line1(int i)
{
  outtextxy(150,450,"DDA LINE DRAWING ALGORITHM");
  dx=(x2-x1);
  dy=(y2-y1);
  if(dx>dy)
    len=dx;
  else
    len=dy;
  rux=(dx/len);
  ruy=(dy/len);
  float sgx=sign(rux);
  float sgy=sign(ruy);
  float x=(x1+(0.5*sgx));
  float y=(y1+(0.5*sgy));
  i=1;
  while(i<=len)
  {
    putpixel(x,y,7);
    x=x+rux;
    y=y+ruy;
    i=i+1;
  }
 }

 int dda::sign(float k)
 {
   if(k<0)
     return -1;
   else if(k>0)
    return 1;
   else
    return 0;
 }

 void bre::line1(int e)
 {
   outtextxy(150,450,"BRESENHAMS'S LINE DRAWING ALGORITHM");
   dx=abs(x2-x1);
   dy=abs(y2-y1);
   x=x1;
   y=y1;
   i=0;
   do
   {
     while(e>=0)
     {
       y=y+1;
       e=e-(2*dx);
     }
     x=x+1;
     e=e+(2*dy);
     putpixel(x,y,3);
     i=i+1;
   }while(i<dx);
 }

 int main()
 {
   
   int gd=DETECT,gm=VGAMAX;
   initgraph(&gd,&gm,NULL);
   dda p;
   bre b;
   int op,e=0,j;
   cout<<"\n1.DDA ALGORITHM \n2.BRESENHAM'S ALGORITHM";
   cout<<"\nEnter your choice: ";
   cin>>op;
   switch(op)
   {
      case 1:p.get();
	     p.line1(j);
	     break;
      case 2:b.get();
	     b.line1(e);
	     break;
   }
   getch();
   closegraph();
return 0;
 }
