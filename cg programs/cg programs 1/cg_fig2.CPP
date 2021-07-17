#include<iostream.h>
#include<conio.h>
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

int main()
{
 bre_circle b;
 
 int gd = DETECT ,gm=VGAMAX;
 initgraph(&gd ,&gm,NULL);
 b.line(300,100,500,100);
 b.line(300,200,500,200);
 b.line(300,200,300,100);
 b.line(500,100,500,200);
 b.line(300,150,400,100);
 b.line(400,100,500,150);
 b.line(500,150,400,200);
 b.line(300,150,400,200);
 b.line(350,125,450,125);
 b.line(450,125,450,175);
 b.line(450,175,350,175);
 b.line(350,175,350,125);
 cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tFIGURE NO 2  ";

 getch();
 closegraph();
return 0;

 }
