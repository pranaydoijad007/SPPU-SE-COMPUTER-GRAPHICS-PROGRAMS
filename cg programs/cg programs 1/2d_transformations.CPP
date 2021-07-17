#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class transformation
{
 private:
	 int i,j;
	 int vert,input[10][3];
	 int tx,ty;
	 int xp,yp;
	 float sx,sy;
	 float angle;
	 float smatrix[10][2],rotmatrix[10][3],x[10][3];
 public:
	 void getcoord();
	 void translate();
	 void scale();
	 void rotateac();
	 void rotatec();
	 void displayin();
	 void displayout();
};
void transformation::getcoord()
{
 cout<<"\n Enter the no. of vertices in the polygon: ";
 cin>>vert;
 for(i=1;i<=vert;i++)
 {
  cout<<"\n Enter the (x,y) coordinates for vertex "<<i<<": ";
  cin>>input[i][1]>>input[i][2];
 }
}
void transformation::displayin()
{
 for(i=1;i<vert;i++)
 {
  line(input[i][1],input[i][2],input[i+1][1],input[i+1][2]);
 }
 line(input[i][1],input[i][2],input[1][1],input[1][2]);
}
void transformation::displayout()
{
 //clrscr();
 for(i=1;i<vert;i++)
 {
  line(x[i][1],x[i][2],x[i+1][1],x[i+1][2]);
 }
 line(x[i][1],x[i][2],x[1][1],x[1][2]);
}
void transformation::translate()
{
 cout<<"\n Enter the translation factors (tx and ty): ";
 cin>>tx>>ty;
 for(i=1;i<=vert;i++)
 {
  x[i][1]=input[i][1]+tx;
  x[i][2]=input[i][2]+ty;
 }
}
void transformation::scale()
{
 cout<<"\n Enter the scaling factors (sx & sy): ";
 cin>>sx>>sy;
 smatrix[1][1]=sx;
 smatrix[2][2]=sy;
 smatrix[1][2]=smatrix[2][1]=0;
 for(i=1;i<=vert;i++)
 {
  x[i][1]=input[i][1]*smatrix[1][1];
  x[i][2]=input[i][2]*smatrix[2][2];
 }
}
void transformation::rotateac()
{
 cout<<"\n Enter the angle of rotation (in degrees): ";
 cin>>angle;
 angle=((3.14*angle)/180);
// rotmatrix[1][1]=rotmatrix[2][2]=cos(angle);
// rotmatrix[1][2]=sin(angle);
// rotmatrix[2][1]=(-1)*sin(angle);
// for(i=1;i<=vert;i++)
// {
// x[i][1]=(input[i][1]*rotmatrix[1][1])+(input[i][2]*rotmatrix[2][1]);
// x[i][2]=(input[i][1]*rotmatrix[1][2])+(input[i][2]*rotmatrix[2][2]);
// }
 cout<<"\n Enter the co-ordinates of the point w.r.t which you want the figure to be rotated: ";
 cin>>xp>>yp;
 rotmatrix[1][1]=rotmatrix[2][2]=cos(angle);
 rotmatrix[1][2]=sin(angle);
 rotmatrix[2][1]=(-1)*sin(angle);
 rotmatrix[1][3]=rotmatrix[2][3]=0;
 rotmatrix[3][1]=-(xp*cos(angle))+(yp*sin(angle))+xp;
 rotmatrix[3][2]=-(xp*sin(angle))-(yp*cos(angle))+yp;
 rotmatrix[3][3]=1;
 input[1][3]=input[2][3]=input[3][3]=input[4][3]=1;
 for(i=1;i<=vert;i++)
 {
  x[i][1]=(input[i][1]*rotmatrix[1][1])+(input[i][2]*rotmatrix[2][1])+(input[i][3]*rotmatrix[3][1]);
  x[i][2]=(input[i][1]*rotmatrix[1][2])+(input[i][2]*rotmatrix[2][2])+(input[i][3]*rotmatrix[3][2]);
  x[i][3]=(input[i][1]*rotmatrix[1][3])+(input[i][2]*rotmatrix[2][3])+(input[i][3]*rotmatrix[3][3]);
  x[i][4]=(input[i][1]*rotmatrix[1][4])+(input[i][2]*rotmatrix[2][4])+(input[i][3]*rotmatrix[3][4]);
 }
}
void transformation::rotatec()
{
 cout<<"\n Enter the angle of rotation (in degrees): ";
 cin>>angle;
 angle=((3.14*angle)/180);
// rotmatrix[1][1]=rotmatrix[2][2]=cos(angle);
// rotmatrix[1][2]=(-1)*sin(angle);
// rotmatrix[2][1]=sin(angle);
// for(i=1;i<=vert;i++)
// {
//  x[i][1]=(input[i][1]*rotmatrix[1][1])+(input[i][2]*rotmatrix[2][1]);
//  x[i][2]=(input[i][1]*rotmatrix[1][2])+(input[i][2]*rotmatrix[2][2]);
// }
 cout<<"\n Enter the co-ordinates of the point w.r.t which you want the figure to be rotated: ";
 cin>>xp>>yp;
 rotmatrix[1][1]=rotmatrix[2][2]=cos(angle);
 rotmatrix[1][2]=(-1)*sin(angle);
 rotmatrix[2][1]=sin(angle);
 rotmatrix[1][3]=rotmatrix[2][3]=0;
 rotmatrix[3][1]=-(xp*cos(angle))-(yp*sin(angle))+xp;
 rotmatrix[3][2]=(xp*sin(angle))-(yp*cos(angle))+yp;
 rotmatrix[3][3]=1;
 input[1][3]=input[2][3]=input[3][3]=input[4][3]=1;
 for(i=1;i<=vert;i++)
 {
  x[i][1]=(input[i][1]*rotmatrix[1][1])+(input[i][2]*rotmatrix[2][1])+(input[i][3]*rotmatrix[3][1]);
  x[i][2]=(input[i][1]*rotmatrix[1][2])+(input[i][2]*rotmatrix[2][2])+(input[i][3]*rotmatrix[3][2]);
  x[i][3]=(input[i][1]*rotmatrix[1][3])+(input[i][2]*rotmatrix[2][3])+(input[i][3]*rotmatrix[3][3]);
  x[i][4]=(input[i][1]*rotmatrix[1][4])+(input[i][2]*rotmatrix[2][4])+(input[i][3]*rotmatrix[3][4]);
 }
}
void main()
{
 //clrscr();
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"../BGI");
 transformation t;
 int ch,chr;
 static int cnt;
 int x=getmaxx();
 int y=getmaxy();
 MENU:
 do
 {
  if(cnt>0)
  {
   //delay(3000);
  // clrscr();
  }
  cout<<"\n \t \t \t \t MAIN MENU ";
  cout<<"\n \t \t \t \t ========= ";
  cout<<"\n 1. Translation ";
  cout<<"\n 2. Scaling ";
  cout<<"\n 3. Rotation ";
  cout<<"\n 4. Exit ";
  cout<<"\n Enter your choice: ";
  cin>>ch;
  switch(ch)
  {
   case 1:
	  t.getcoord();
	  t.translate();
//	  clrscr();
	  line(0,y/2,x,y/2);
	  line(x/2,0,x/2,y);
	  t.displayin();
	  t.displayout();
	  getch();
	  cnt++;
	  break;
   case 2:
	  t.getcoord();
	  t.scale();
//  clrscr();
	  line(0,y/2,x,y/2);
	  line(x/2,0,x/2,y);
	  t.displayin();
	  t.displayout();
	  getch();
	  cnt++;
	  break;
   case 3:
	  cout<<"\n \t \t \t Rotation Menu ";
	  cout<<"\n \t \t \t ============= ";
	  cout<<"\n 1. Anti-clockwise Rotation ";
	  cout<<"\n 2. Clockwise Rotation ";
	  cout<<"\n 3. Go back to main menu ";
	  cout<<"\n Enter your choice: ";
	  cin>>chr;
	  switch(chr)
	  {
	   case 1:
		  t.getcoord();
		  t.rotateac();
	//	  clrscr();
		  line(0,y/2,x,y/2);
		  line(x/2,0,x/2,y);
		  t.displayin();
		  t.displayout();
		  getch();
		  cnt++;
		  break;
	   case 2:
		  t.getcoord();
		  t.rotatec();
    //		  clrscr();
		  line(0,y/2,x,y/2);
		  line(x/2,0,x/2,y);
		  t.displayin();
		  t.displayout();
		  getch();
		  cnt++;
		  break;
	   case 3:
		  goto MENU;
	  }
	  break;
   case 4:
	  exit(0);
  }
 }while(ch>=1 && ch<=4);
 getch();
return 0;
}