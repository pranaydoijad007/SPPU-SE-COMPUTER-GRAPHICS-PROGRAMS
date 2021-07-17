#include<iostream>
//#include<conio.h>
#include<stdio.h>
//#include<dos.h>
#include<graphics.h>
using namespace std;
union REGS in,out;
class mouse
{
  int v[30],i,j,f,n;
  public:
   void showmouse();
   void setmouse();
   void hidemouse();
   void polygon(int &);
   void seedfill(int,int);
   void polydraw();
   void seed();
   void dimension();
};
void mouse::dimension()
{
  in.x.ax=7;
  int86(51,&in,&out);
  in.x.cx=getmaxx()/2;
  in.x.cx=getmaxx();

  /*in.x.ax=8;
  int86(51,&in,&out);
  in.x.cx=getmaxy()/2;
  in.x.cx=getmaxy();*/

}
void mouse::showmouse()
{
  in.x.ax=1;
  int86(51,&in,&out);
}
void mouse::setmouse()
{
  in.x.ax=0;
  int86(51,&in,&out);
}
void mouse::hidemouse()
{
  in.x.ax=2;
  int86(51,&in,&out);
}
void mouse::polygon(int &size)
{
  size--;
  for(i=0;i<size;i++)
  {
    f=2*i;
    j=f+2;
    line(v[f],v[f+1],v[j],v[j+1]);
  }
}
void mouse::seedfill(int a,int b)
{
  if(getpixel(a,b)!=15)
  {
    putpixel(a,b,15);
    seedfill(a+1,b);
    seedfill(a-1,b);
    seedfill(a,b+1);
    seedfill(a,b-1);
    /*seedfill(a-1,b-1);
    seedfill(a-1,b+1);
    seedfill(a+1,b-1);
    seedfill(a+1,b+1);*/
  }
}
void mouse::polydraw()
{
  cout<<"Enter the no of vertex:"<<endl;
  cin>>n;
  in.x.ax=3;
  int86(51,&in,&out);
  for(i=0;i<n;i++)
  {
    f=2*i;
     while(out.x.bx!=(i%2)+1)
     {
      in.x.ax=3;
      int86(51,&in,&out);
      v[f]=out.x.cx;
      v[f+1]=out.x.dx;
     }
    delay(5);
  }
  f=2*i;
  v[f]=v[0];
  v[f+1]=v[1];
  n++;
  hidemouse();
  setcolor(15);
  polygon(n);

}
void mouse::seed()
{
  int a,b,r;
  in.x.bx=0;
  do
  {
   showmouse();
   cout<<"click the point to fill the color:"<<endl;
   while(out.x.bx!=0)
   {
     in.x.ax=3;
     int86(51,&in,&out);
   }
   while(out.x.bx!=1)
   {
     in.x.ax=3;
     int86(51,&in,&out);
     a=out.x.cx;
     b=out.x.dx;
   }
   hidemouse();
  // cout<<"OUT.x.bx:"<<out.x.bx<<endl;
   seedfill(a,b);
   cout<<"enter 0 to continue:"<<endl;
   cin>>r;
  }while(r==0);
}
void main()
{
  int gd=DETECT,gm=VGAMAX;
  initgraph(&gd,&gd,"NULL");
  mouse p;
  p.showmouse();
  //p.dimension();
  p.polydraw();
  p.seed();
  getch();
  clrscr();
}
