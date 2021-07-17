#include<iostream>
//#include<conio.h>
#include<math.h>
#include<graphics.h>
using namespace std;
#define X 319
#define Y 239
void change(int &a,int &b)
{
  a=a+X;
  b=Y-b;
}
void coordinate(int &a,int &b)
{
  a=a-X;
  b=Y-b;
}
class transform
{
  int n,f,i,p1,p2,v[15],v2[15],v3[15],tx,ty;
  float sx,sy,x,y,p[1][3],t[10][10],s[10][10],r[10][10],q;
  public:
  void getdata();
  void axis();
  void scaling(int &,int &);
  void scale();
  void translation(int &,int &);
  void translate();
  void rotate();
  void rotating(float &,float &,int &);
};
void transform::scaling(int &a,int &b)
{
  s[0][0]=sx;
  s[0][1]=0;
  s[1][0]=0;
  s[1][1]=sy;
  p[0][0]=a;
  p[0][1]=b;
  q=p[0][0]*s[0][0];
  p[0][0]=q+(p[0][1]*s[1][0]);
  q=p[0][0]*s[0][1];
  p[0][1]=q+(p[0][1]*s[1][1]);
  a=p[0][0];
  b=p[0][1];
  cout<<a<<" "<<b<<endl;
}
void transform::scale()
{
    cout<<"Enter the X-factor:"<<endl;
  cin>>sx;
  cout<<"Enter the Y-factor:"<<endl;
  cin>>sy;
  for(i=0;i<n;i++)
  {
   f=2*i;
   coordinate(v[f],v[f+1]);
   scaling(v[f],v[f+1]);
   change(v[f],v[f+1]);
  }
  i=2*i;
  v[i]=v[0];
  v[i+1]=v[1];
  axis();
  drawpoly(n+1,v);
}
void transform::translation(int &a,int &b)
{
  float temp,temp1,temp2;
  t[0][0]=t[1][1]=t[2][2]=p[0][2]=1;
  t[0][1]=t[0][2]=t[1][0]=t[1][2]=0;
  t[2][0]=tx;
  t[2][1]=ty;
  p[0][0]=a;
  p[0][1]=b;
  p[0][2]=1;
  temp=p[0][0];
  temp1=p[0][1];
  p[0][0]=(temp*t[0][0])+(p[0][1]*t[1][0])+(p[0][2]*t[2][0]);
  p[0][1]=(temp*t[0][1])+(p[0][1]*t[1][1])+(p[0][2]*t[2][1]);
  a=p[0][0];
  b=p[0][1];

}
void transform::translate()
{
  cout<<"Enter the translation factor for x:"<<endl;
  cin>>tx;
  cout<<"Enter the translation factor for y:"<<endl;
  cin>>ty;
  for(i=0;i<n;i++)
  {
   f=2*i;
   coordinate(v[f],v[f+1]);
   translation(v[f],v[f+1]);
   change(v[f],v[f+1]);
  }
  i=2*i;
  v[i]=v[0];
  v[i+1]=v[1];
  axis();
  drawpoly(n+1,v);
}
void transform::rotating(float &a,float &b,int &l)
{
  float c;
  float temp;

  //cout<<cos(c)<<"  "<<sin(c)<<endl;
  r[0][0]=cos((l*M_PI)/180);
  r[0][1]=sin((l*M_PI)/180);
  //cout<<r[0][0]<<"  "<<r[0][1]<<endl;
  r[1][0]=-r[0][1];
  r[1][1]=r[0][0];
  p[0][0]=a;
  p[0][1]=b;
    temp=p[0][0];
  p[0][0]=(p[0][0]*r[0][0])+(p[0][1]*r[1][0]);
  p[0][1]=(temp*r[0][1])+(p[0][1]*r[1][1]);
  a=p[0][0];
  b=p[0][1];
  //cout<<a<<"  "<<b<<endl;
}
void transform::rotate()
{
  int angle;
  float p3,p4;
  cout<<"enter the angle:"<<endl;
  cin>>angle;
  for(i=0;i<n;i++)
  {
   f=2*i;
   p3=v[f]-X;
   p4=Y-v[f+1];
   rotating(p3,p4,angle);
   //change(v[f],v[f+1]);
   v[f]=p3+X;
   v[f+1]=Y-p4;
   //cout<<v[f]<<"  "<<v[f+1]<<endl;
  }
  i=2*i;
  v[i]=v[0];
  v[i+1]=v[1];
  axis();
  drawpoly(n+1,v);

}
void transform::axis()
{
  cleardevice();
  setcolor(4);
  line(0,Y,2*X,Y);
  line(X,0,X,2*Y);
  setcolor(15);
}
void transform::getdata()
{
  cout<<"Enter the no of vertices:"<<endl;
  cin>>n;
  for(i=0;i<n;i++)
  {
   cout<<"Enter the vertex no:"<<i+1<<endl;
   cin>>x>>y;
   f=2*i;
   x=x+X;
   y=Y-y;
   v[f]=x;
   v[f+1]=y;
  }
  i=2*i;
  v[i]=v[0];
  v[i+1]=v[1];
  axis();
  drawpoly(n+1,v);
}
int main()
{
  int gd=DETECT,gm=VGAMAX;
  initgraph(&gd,&gd,"NULL");
  transform p;
  int ch,r=0;
  p.getdata();
  do
  {
    cout<<"Enter the options:";
    cout<<"1.scaling:";
    cout<<"2.translate:";
    cout<<"3.rotate:";
    cin>>ch;
    switch(ch)
    {
      case 1:
	 p.scale();
	 break;
      case 2:
	p.translate();
	break;
     case 3:
	p.rotate();
	break;
     default:
	  r=1;
	  break;
     cout<<endl;
    }
    //closegraph();
  }while(r==0);
  getch();
  return 0;
}
