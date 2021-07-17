#include<iostream>
//#include<conio.h>
#include<graphics.h>
#include<math.h>
using namespace std;
class pixel
{
  float a,b,x,y,dx,dy,len,d,rux,ruy,tx,ty;
  int x1,y1,i;
  public:
    pixel();
    void shape();
    void bre_cir(int ,int ,int);
    void disp(int,int);
    void line1(int ,int ,int ,int);
    int sign(float );
};
pixel::pixel()
{
  tx=cos(M_PI/6);
  ty=sin(M_PI/6);
  tx=100*tx;
  ty=ty*100;
}

/*void pixel::get()
{
  cout<<"\nEnter co-ordinates of circle: ";
  cin>>x;
  cin>>y;
  cout<<"\nEnter radius of circle: ";
  cin>>r;
}
*/
void pixel::bre_cir(int x,int y,int r)
{
  d=3-(2*r);
  x1=0;
  y1=r;
  do
  {
    if(d<=0)
    {
      d=d+(4*x1)+6;
    }
    else
    {
      d=d+4*(x1-y1)+10;
      y1=y1-1;
    }
    x1=x1+1;
    disp(x,y);
  }while(x1<=y1);
}

void pixel::disp(int x,int y)
{
  outtextxy(150,450,"Circle drawing using Bresenhams's Algorithm");
  putpixel(x1+x,y1+y,3);
  putpixel(x1+x,y-y1,3);
  putpixel(x-x1,y1+y,3);
  putpixel(x-x1,y-y1,3);
  putpixel(x+y1,y+x1,3);
  putpixel(x+y1,y-x1,3);
  putpixel(x-y1,y+x1,3);
  putpixel(x-y1,y-x1,3);
}
void pixel::shape()
{
  bre_cir(319,239,100);
  line1(319,139,319-tx,239+ty);
  line1(319-tx,239+ty,319+tx,239+ty);
  line1(319,139,319+tx,239+ty);
  bre_cir(319,239,50);
}
void pixel::line1(int x1,int y1,int x2,int y2)
{
  outtextxy(150,450,"DDA LINE DRAWING ALGORITHM");
  dx=(x2-x1);
  dy=(y2-y1);
  if(dx>dy)
    len=dx;
  else
    len=dy;
  rux=(dx/len);
  ruy=(dy/len);
  float sgx=sign(rux);
  float sgy=sign(ruy);
  float x=(x1+(0.5*sgx));
  float y=(y1+(0.5*sgy));
  i=1;
  while(i<=len)
  {
    putpixel(x,y,7);
    x=x+rux;
    y=y+ruy;
    i=i+1;
  }
 }

 int pixel::sign(float k)
 {
   if(k<0)
     return -1;
   else if(k>0)
    return 1;
   else
    return 0;
 }
int main()
{
  int gd=DETECT,gm=VGAMAX;
  initgraph(&gd,&gm,"NULL");
  pixel p;
  p.shape();
  //p.bre_cir();
  getch();
  closegraph();
	return 0;
}


