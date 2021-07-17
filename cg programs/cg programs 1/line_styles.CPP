#include<iostream>
#include<math.h>
#include<graphics.h>
#include<stdlib.h>
using namespace std;

class linealgo
{
 private:
	 int x1,y1,x2,y2,dx,dy,len,idx,idy,sdx,sdy,i,e;
	 float x,y;
 public:
	 void dda(int);
};
void linealgo::dda(int ch)
{
 x1=y1=200;
 x2=y2=300;
 dx=abs(x2-x1);
 dy=abs(y2-y1);
 len=dx>=dy?dx:dy;
 idx=dx/len;
 idy=dy/len;
 if(dx>0)
   sdx=1;
 else if(dx<0)
   sdx=-1;
 else
   sdx=0;
 if(dy>0)
   sdy=1;
 else if(dy<0)
   sdy=-1;
 else
   sdy=0;
 x=x1+(0.5*sdx);
 y=y1+(0.5*sdy);
 i=1;
 if(ch==1)
 {
  while(i<=len)
  {
   putpixel(x,y,YELLOW);
   x=x+idx;
   y=y+idy;
   i+=1;
  }
 }
 else if(ch==2)
 {
 while(i<=len)
   {
    putpixel(x,y,RED);
    putpixel(x+1,y,RED);
    putpixel(x+2,y,RED);
    putpixel(x+3,y,RED);
    x+=idx;
    y+=idy;
    i+=1;
    }

 }
 else if(ch==3)
 {
 while(i<=len)
  {
   if(i%5!=0)
   {
    putpixel(x,y,RED);
    x+=idx;
    y+=idy;
    i+=1;
   }
   else
   {
    x+=idx;
    y+=idy;
    i+=1;
   }
  }

 }
 else if(ch==4)
 {
  while(i<=len)
  {
   if(i%2==0)
   {
    putpixel(x,y,YELLOW);
    x+=idx;
    y+=idy;
    i+=1;
   }
   else
   {
    x+=idx;
    y+=idy;
    i+=1;
   }
  }
 }
 else if(ch==5)
 {
 while(i<=len)
  {
   if(i%5!=0)
   {
    putpixel(x,y,YELLOW);
    x+=idx;
    y+=idy;
    i+=1;
   }
   else
   {
    x+=idx+3;
    y+=idy+3;
    i+=+3;
    putpixel(x,y,YELLOW);
    x+=idx+3;
    y+=idx+3;
    i+=+3;
   }
}
 }
}
int main()
{
 int gd=DETECT,gm=VGAMAX;
 initgraph(&gd,&gm,NULL);
 int ch;
 linealgo l;
 do
 {
  cout<<"\n \t \t \t \t \t MENU ";
  cout<<"\n \t \t \t \t \t ==== ";
  cout<<"\n 1. Solid Line ";
  cout<<"\n 2. Thick line ";
  cout<<"\n 3. Dashed Line ";
  cout<<"\n 4. Dotted Line ";
  cout<<"\n 5. Dashed and Dotted Line ";
  cout<<"\n 6. Exit ";
  cout<<"\n Enter your choice: ";
  cin>>ch;
  switch(ch)
  {
   case 1:
	
	  l.dda(1);
	  break;
   case 2:
	 
	  l.dda(2);
	  break;
   case 3:
	  l.dda(3);
	  break;
   case 4:
	 
	  l.dda(4);
	  break;
   case 5:
	 
	  l.dda(5);
	  break;
   case 6:
	  exit(0);
  }
 }while(ch>=1&&ch<=6);
return 0;
}