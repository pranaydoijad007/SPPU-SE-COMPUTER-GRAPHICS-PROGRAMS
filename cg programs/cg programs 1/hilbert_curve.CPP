
#include<iostream>
#include<stdlib.h>
#include<graphics.h>
using namespace std;
class  hil
{
private:
       int i,j;
public:
	void move(int j,int h,int &x,int &y);
	void hilbert(int,int,int,int,int,int,int& ,int&);
};
void hil::move(int j,int h,int &x,int &y)
{
	if(j==1)
	   y=y-h;
	else if(j==2)
	   x=x+h;
	else if(j==3)
	   y=y+h;
	else if(j==4)
	   x=x-h;

	lineto(x,y);
}
void hil::hilbert(int r,int d,int l,int u,int i,int h,int &x ,int &y)
{
	if(i>0)
	{
	i--;
	hilbert(d,r,u,l,i,h,x,y);
	move(r,h,x,y);
	hilbert(r,d,l,u,i,h,x,y);
	move(d,h,x,y);
	hilbert(r,d,l,u,i,h,x,y);
	move(l,h,x,y);
	hilbert(u,l,d,r,i,h,x,y);
	}
}
int main()
{
hil h2;
int gd=DETECT,gm=VGAMAX;
initgraph(&gd,&gm,NULL);
	int n,x1,y1;
	int x0=150,y0=100,x,y,h=10,r=2,d=3,l=4,u=1;

	cout<<"\n Give Value of n :";
	cin>>n;
	x=x0;
	y=y0;
       moveto(x,y);
       h2.hilbert(r,d,l,u,n,h,x,y);
getch();
closegraph();
return 0;
}
