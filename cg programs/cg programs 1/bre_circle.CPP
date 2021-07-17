#include<iostream>
#include<graphics.h>
using namespace std;
class br_circle
{
private:
	int x,y,r;
public:
	void getdata();
	void plot(int ,int ,int );
	void display(int ,int ,int ,int );
};
void br_circle::getdata()
{
 cout<<"\nEnter the radius :";
 cin>>r;
 cout<<"Enter X and Y co-ordinates :";
 cin>>x>>y;
 plot(x,y,r);
}
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
 initgraph(&gd ,&gm,NULL);
 br_circle b;
 b.getdata();
 getch();
 closegraph();
 return 0;
}
