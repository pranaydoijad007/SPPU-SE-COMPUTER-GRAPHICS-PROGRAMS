

#include<iostream.h>
//#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
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

 // cout<<"X1: ";
  cin>>x1;
 // cout<<"Y1: ";
  cin>>y1;
  //cout<<"\nEnter end co-ordinates: ";
//  cout<<"X2: ";
  cin>>x2;
//  cout<<"Y2: ";
  cin>>y2;
}

void dda::line1(int i)
{
//  outtextxy(150,450,"DDA LINE DRAWING ALGORITHM");
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


 void main()
 {
   clrscr();
   int gd=DETECT,gm=VGAMAX;
   initgraph(&gd,&gm,"NULL");
   dda p;

   int op,j;
   for(int i=0;i<12;i++)
   {
      p.get();
	     p.line1(j);
    }
   getch();
   closegraph();
 }
