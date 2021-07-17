#include<graphics.h>
//#include<conio.h>
using namespace std;
int main()
{
	
	int gd=DETECT,gm=VGAMAX;
	initgraph(&gd,&gm,NULL);
	float y=getmaxy();
	setbkcolor(13);
       //	rectangle(0,0,600,500);


	circle(300,100,80);
	setcolor(15);
	circle(260,80,20);
	circle(340,80,20);

	line(300,100,320,120);
	line(300,100,280,120);
	line(280,120,320,120);

	rectangle(260,140,340,160);



	line(300,180,300,360);

	line(300,260,200,220);
       line(300,260,400,220);
       line(300,360,200,500);
       line(300,360,400,500);

	getch();
	closegraph();

}
