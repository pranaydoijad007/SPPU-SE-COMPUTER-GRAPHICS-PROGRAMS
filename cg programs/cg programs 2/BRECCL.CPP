#include<iostream>
#include<graphics.h>

#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
using namespace std;
class data
{
public:
int x,y,r,d,x1,y1,color;
public:
void get();
};
class bhm:public data
{
public:
void bm();
};
void data::get()
{
cout<<"enter radius of circle: ";
cin>>r;
/*cout<<"enter colour of your circle";
cin>>color;*/
cout<<"enter centre of circle: ";
cin>>x1>>y1;
}

void bhm::bm()
{
 d=3-(2*r);
x=0;
y=r;
do
{
putpixel(x1+x,y1+y,10);
delay(50);
putpixel(x1-x,y1+y,1);delay(1);
putpixel(x1+x,y1-y,2);delay(1);
putpixel(x1-x,y1-y,3);delay(1);
putpixel(x1+y,y1+x,4);delay(1);
putpixel(x1+y,y1-x,5);delay(1);
putpixel(x1-y,y1+x,8);delay(1);
putpixel(x1-y,y1-x,9);delay(1);
/*putpixel(x1+x,y1+y,color);


delay(50);
putpixel(x1-x,y1+y,color);delay(50);
putpixel(x1+x,y1-y,color);delay(50);
putpixel(x1-x,y1-y,color);delay(50);
putpixel(x1+y,y1+x,color);delay(50);
putpixel(x1+y,y1-x,color);delay(50);
putpixel(x1-y,y1+x,color);delay(50);
putpixel(x1-y,y1-x,color);delay(50);
*/
if(d<0)
{
d=d+4*x+6;
}
else
{
d=d+4*(x-y)+10;
y=y-1;
}
x=x+1;

}
while(x<y);
}
int main()
{

int gd = DETECT,gm=VGAMAX;
initgraph(&gd,&gm,NULL);
cleardevice();
bhm b;
b.get();
b.bm();
getch();
closegraph();
return 0;
}
