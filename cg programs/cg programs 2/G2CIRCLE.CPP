#include<iostream>
//#include<conio.h>
#include<graphics.h>
#include<math.h>
using namespace std;

class pixel
{
  int x,y,x1,y1,r,d;
  public:
  void get();
  void bressenham();

};
void pixel::get()
{
 cout<<"Enter the radius of circle:"<<endl;
 cin>>r;
 cout<<"Enter the cordinate:"<<endl;
	cin

}
void pixel::bressenham()
{
  d=3-(2*r);
  x=200;
  y=200+r;
  do
  {
    putpixel(x+200,y+200,7);
    putpixel(y+200,x+200,7);
    putpixel(y+200,-x+200,7);
    putpixel(x+200,-y+200,7);
    putpixel(-x+200,-y+200,7);
    putpixel(-y+200,-x+200,7);
    putpixel(-y+200,x+200,7);
    if(d<0)
    {
      d=d+(4*(x-y))+6;
    }
    else
    {
      d=d+(4*(x-y))+10;
      y=y-1;
    }
    x=x+1;
  }while(x<y);
}
int main()
{
  pixel p;
  int gd=DETECT,gm=VGAMAX;
  p.get();
  initgraph(&gd,&gm,NULL);
  p.bressenham();
  getch();
	return 0;
}
