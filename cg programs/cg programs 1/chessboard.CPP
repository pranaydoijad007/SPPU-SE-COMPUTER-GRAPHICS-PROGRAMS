#include<iostream>
#include<graphics.h>
#include<math.h>
class chessboard
{
 private:
	 int x1,y1,x2,y2,dx,dy,len,idx,idy,sdx,sdy,i,e,j;
	 float x,y;
 public:
	 void dda(float,float,float,float);
	 void bresenham(int,int,int,int);
	 void seedfill(int,int,int,int);
	 void plotcb();
	 void rotate();
};
void chessboard::dda(float x1,float y1,float x2,float y2)
{
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
 while(i<=len)
 {
  putpixel(x,y,WHITE);
  x=x+idx;
  y=y+idy;
  i+=1;
 }
}
void chessboard::bresenham(int x1,int y1,int x2,int y2)
{
 dx=abs(x2-x1);
 dy=abs(y2-y1);
 x=x1;
 y=y1;
 e=2*dy-dx;
 i=0;
 do
 {
  if(e>=0)
  {
   y+=1;
   e=e-2*dx;
  }
  x+=1;
  e=e+2*dy;
  putpixel(x,y,WHITE);
  i+=1;
 }while(i<=dx);
}
void chessboard::seedfill(int x,int y,int newcolor,int oldcolor)
{
 int current;
 current=getpixel(x,y);
 if(current==oldcolor)
 {
  putpixel(x,y,WHITE);
  seedfill(x-1,y,newcolor,oldcolor);
  seedfill(x+1,y,newcolor,oldcolor);
  seedfill(x,y-1,newcolor,oldcolor);
  seedfill(x,y+1,newcolor,oldcolor);
 }
void chessboard::plotcb()
{
    bresenham(220,200,299,200);
   bresenham(220,220,299,220);
   bresenham(220,240,299,240);
   bresenham(220,260,299,260);
   bresenham(219,280,299,280);
   dda(220,200,220,280);
   dda(240,200,240,280);
   dda(260,200,260,280);
   dda(280,200,280,280);
   dda(300,200,300,280);
   seedfill(221,201,WHITE,BLACK);
   seedfill(221,241,WHITE,BLACK);
   seedfill(261,201,WHITE,BLACK);
   seedfill(261,241,WHITE,BLACK);
   seedfill(241,221,WHITE,BLACK);
   seedfill(281,221,WHITE,BLACK);
   seedfill(241,261,WHITE,BLACK);
   seedfill(281,261,WHITE,BLACK);
}
void chessboard::rotate()
{
 float angle,rm[10][3];
 angle=((3.14*45)/180);
 rm[1][1]=rm[2][2]=cos(angle);
 rm[1][3]=rm[2][3]=0;
 rm[3][3]=1;
 rm[1][2]=sin(angle);
 rm[2][1]=(-1)*sin(angle);
 float hxx1[5],hxx2[5],hyy1[5],hyy2[5];
 float vxx1[5],vxx2[5],vyy1[5],vyy2[5];
 rm[3][1]=(-220*cos(angle))+(280*sin(angle))+220;
 rm[3][2]=(-220*sin(angle))-(280*cos(angle))+280;
 for(i=1;i<=5;i++)
 {
  hxx1[i]=(220*rm[1][1])+((180+20*i)*rm[2][1])+(1*rm[3][1]);
  hyy1[i]=(220*rm[1][2])+((180+20*i)*rm[2][2])+(1*rm[3][2]);
  hxx2[i]=(300*rm[1][1])+((180+20*i)*rm[2][1])+(1*rm[3][1]);
  hyy2[i]=(300*rm[1][2])+((180+20*i)*rm[2][2])+(1*rm[3][2]);
 }
 for(i=1;i<=5;i++)
 {
  line(hxx1[i],hyy1[i],hxx2[i],hyy2[i]);
 }
 for(i=1;i<=5;i++)
 {
  vxx1[i]=((200+20*i)*rm[1][1])+(200*rm[2][1])+(1*rm[3][1]);
  vyy1[i]=((200+20*i)*rm[1][2])+(200*rm[2][2])+(1*rm[3][2]);
  vxx2[i]=((200+20*i)*rm[1][1])+(280*rm[2][1])+(1*rm[3][1]);
  vyy2[i]=((200+20*i)*rm[1][2])+(280*rm[2][2])+(1*rm[3][2]);
 }
 for(i=1;i<=5;i++)
 {
  line(vxx1[i],vyy1[i],vxx2[i],vyy2[i]);
 }
 seedfill(hxx2[0]-1,hyy2[0]-1,WHITE,BLACK);
 seedfill(hxx2[0]-41,hyy2[0]-41,WHITE,BLACK);
 seedfill(hxx2[0],hyy2[0]-61,WHITE,BLACK);
 seedfill(hxx2[0]-31,hyy2[0]-61,WHITE,BLACK);
 seedfill(hxx2[0]-10,hyy2[0]-41,WHITE,BLACK);
 seedfill(hxx2[0]-10,hyy2[0]-91,WHITE,BLACK);
 seedfill(hxx2[3],hyy2[3]-1,WHITE,BLACK);
 seedfill(hxx2[3],hyy2[3]-41,WHITE,BLACK);
}
int main()
{
 clrscr();
 int gd=DETECT,gm=vgamax;
 initgraph(&gd,&gm,NULL);
 chessboard c;
 c.plotcb();
 delay(3000);
 cleardevice();
 c.rotate();
 getch();
}
