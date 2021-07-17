#include<iostream>
#include<graphics.h>
using namespace std;

class br_circle
{
private:
	int x,y,r;
	int x1,y1,x2,y2;


public:
	void line(int x1,int y1,int x2,int y2);
	int sign(int);
	void getdata();
	void plot(int ,int ,int );
	void display(int ,int ,int ,int );
};
void br_circle::line(int x1,int y1,int x2,int y2)
{
int i=0,dx,dy,e;
dx=x2-x1;
dy=y2-y1;
if(dx==0 && dy==0)
{
putpixel(x1,y1,WHITE);
}
e=2*dy-dx;
do
{
while(e>=0)
{
y1++;
e=e-2*dx;
}
x1++;
e=e+2*dy;
putpixel(x1,y1,WHITE);
i++;
}while(i<=dx);
}
/*
void br_circle::getdata()
{
 cout<<"\nEnter the radius :";
 cin>>r;
 cout<<"Enter X and Y co-ordinates :";
 cin>>x>>y;
 plot(x,y,r);
}
*/
void br_circle::plot(int x,int y,int r)
{
 float d;
 int x1,y1;
 x1=0;
 y1=r;
 d=3-2*r;
 do
 {
  if(d<=0)
   {
    d=d+(4*x1)+6;
   }
  else
   {
    d=d+4*(x1-y1)+10;
    y1--;
   }
 x1++;
 display(x1,y1,x,y);
 }while(x1<y1);
}
void br_circle::display(int x1,int y1,int x,int y)
{
 putpixel(x1+x,y1+y,WHITE);
 putpixel(x1+x,y-y1,WHITE);
 putpixel(x-x1,y1+y,WHITE);
 putpixel(x-x1,y-y1,WHITE);
 putpixel(x+y1,y+x1,WHITE);
 putpixel(x+y1,y-x1,WHITE);
 putpixel(x-y1,y+x1,WHITE);
 putpixel(x-y1,y-x1,WHITE);
}
int main()
{
 
 int gd = DETECT ,gm=VGAMAX;
 initgraph(&gd ,&gm, NULL);
 br_circle b;
 /*
 line(200,300,300,300);
 line(300,300,250,250);
 line(200,300,250,250);
 b.plot(250,275,45);
 */
 b.line(250,275,350,275);
 line(250,275,300,200);
 line(350,275,300,200);
 b.plot(300,253,55);
 b.plot(300,248,26);
 getch();
 closegraph();
 return 0;
}
