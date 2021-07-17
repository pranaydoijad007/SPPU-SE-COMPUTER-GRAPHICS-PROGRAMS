#include<iostream>
//#include<conio.h>
#include<math.h>
#include<graphics.h>
using namespace std;
class pixel
{
  int x1,x2,y1,y2,length,e,i;
  float dx,dy,x,y;
  public:
  void get();
  void dda();
  void bressenham();
};
void pixel::get()
{
cout<<"Enter the first points:"<<endl;
cin>>x1>>y1;
cout<<"Enter the second points:"<<endl;
cin>>x2>>y2;

}
void pixel::dda()
{
  if(abs(x2-x1)>=abs(y2-y1))
    length=abs(x2-x1);
  else
    length=abs(y2-y1);
  dx=x2-x1;
  dx=dx/length;
  dy=y2-y1;
  dy=dy/length;
  if(dx>=0)
  x=x1+0.5;
  else
  x=x1-0.5;
  if(dy>=0)
  y=y1+0.5;
  else
  y=y1-0.5;
  i=1;
  while(i<=length)
  {
    putpixel(x,y,7);
    x=x+dx;
    y=y+dy;
    i=i+1;
  }


}
void pixel::bressenham()
{
  dx=abs(x2-x1);
  dy=abs(y2-y1);
  x=x1;
  y=y1;
  e=2*dy;
  e=e-dx;
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
   putpixel(x,y,4);
   i=i+1;
  }while(i<=dx);

}
void main()
{
  pixel p;
  int ch,r=0;
  int gd=DETECT,gm=VGAMAX;
 initgraph(&gd,&gm,"NULL");
 do
 {
  cout<<"ENter the options:"<<endl;
  cout<<"1.DDA"<<endl;
  cout<<"2.bressenham:"<<endl;
  cin>>ch;
  switch(ch)
  {
    case 1:
      p.get();
      p.dda();
      break;
   case 2:
      p.get();
      p.bressenham();
      break;
    default:
     r=1;
   }
 }while(r==0);
  getch();
   clrscr();
}
