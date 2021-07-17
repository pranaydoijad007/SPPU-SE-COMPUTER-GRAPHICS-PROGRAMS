#include<iostream>
#include<graphics.h>
#include<stdlib.h>
using namespace std;
class line_algo
{
	int x1,y1,x2,y2;
	public:
	void getpts();
	void line(float);
	void line();
	int sign(int);
};
void line_algo::line()
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
void line_algo::getpts()
{
cout<<"Enter the starting point co-ordinates:";
cin>>x1>>y1;
cout<<"Enter the end point co-ordinates:";
cin>>x2>>y2;
}
void line_algo::line(float f)
{
float len,dx,dy;
dx=x2-x1;
dy=y2-y1;
if(dx==0 && dy==0)
{
putpixel(x1,y1,WHITE);
}
len=dx>dy?dx:dy;
dx=(x2-x1)/len;
dy=(y2-y1)/len;
int i=0;
x1=x1+0.5*sign(dx);
y1=y1+0.5*sign(dy);
while(i<=len)
{
putpixel(x1,y1,WHITE);
x1=x1+dx;
y1=y1+dy;
i++;
f++;
}
}
int line_algo::sign(int d)
{
if(d==0)
{
return 0;
}
else
{
int s=d>0?1:-1;
return s;
}
}
int main()
{
int ch,gd=DETECT,gm=VGAMAX;

initgraph(&gd,&gm,NULL);
do
{
cout<<"\nWelcome";
cout<<"\n1.Construct line using DDA Algorithm:";
cout<<"\n2.Construct line using Bresenham's Algorithm:";
cout<<"\n3.Exit";
cout<<"\nEnter your choice:";
cin>>ch;
switch(ch)
{
case 1:
	{
	int gd=DETECT,gm=VGAMAX;
	initgraph(&gd,&gm,NULL);
	line_algo l;
	l.getpts();
	l.line(1.1);
	getch();
	closegraph();break;
	}
case 2:
	{
	int gd=DETECT,gm=VGAMAX;
	initgraph(&gd,&gm,NULL);
	line_algo l;
	l.getpts();
	l.line();
	getch();
	closegraph();break;
	}
case 3:exit(0);
}
}while(ch>0 && ch<4);
	getch();
return 0;

}
