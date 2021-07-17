#include<iostream>
//#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
//#include<dos.h>
using namespace std;
class dda
{
  public:
      float a,b,x,y,dx,dy,len;
      int i;
      float rux,ruy;
      void line1(int ,int ,int ,int );
      int sign(float k);
      void shape();
      void get();
};
void dda::shape()
{
  cleardevice();
  line1(a-50,b-50,a+50,b-50);
  line1(a-50,b-50,a-50,b+50);
  line1(a-50,b+50,a+50,b+50);
  line1(a+50,b-50,a+50,b+50);
  line1(a-100,b-100,a+100,b-100);
  line1(a-100,b-100,a-100,b+100);
  line1(a-100,b+100,a+100,b+100);
  line1(a+100,b-100,a+100,b+100);
  line1(a,b-100,a+100,b);
  line1(a,b-100,a-100,b);
  line1(a-100,b,a,b+100);
  line1(a,b+100,a+100,b);
  /*line1(219,139,219,339);
  line1(219,339,419,339);
  line1(419,139,419,339);
  line1(319,139,419,239);
  line1(319,139,219,239);
  line1(219,239,319,339);
  line1(319,339,419,239);
  */
}

void dda::get()
{
  cout<<"\nEnter starting co-ordinates: ";
  cout<<"\na: ";
  cin>>a;
  cout<<"b: ";
  cin>>b;
  /*cout<<"\nEnter end co-ordinates: ";
  cout<<"\nX2: ";
  cin>>x2;
  cout<<"\nY2: ";
  cin>>y2; */
}
/*class bre:public dda
{
  public:
     void line1(int e);
};*/

void dda::line1(int x1,int y1,int x2,int y2)
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
 int main()
{
 int gd=DETECT,gm=VGAMAX;
  initgraph(&gd,&gm,"NULL");
  dda l;
  l.get();
  //l.line1();
  l.shape();
  getch();
 closegraph();

}
