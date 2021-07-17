#include<graphics.h>
using namespace std;
int main()
{
 int gd=DETECT,gm=VGAMAX;
 initgraph(&gd,&gm,NULL);
 setcolor(BROWN);
 rectangle(200,200,400,400);//main rectangle
 rectangle(100,200,200,400);//side rectangle
 rectangle(280,320,335,400);//main door
 rectangle(130,320,170,400);//side door
 line(200,200,300,50);//main roof left part
 line(400,200,300,50);// main roof right part
 line(100,200,200,50);//other roof left
 line(200,50,300,50);//other roof horizontal
 rectangle(220,220,260,260);//left window
 rectangle(340,260,380,220);//right window
 line(220,240,260,240);//left window hor
 line(240,220,240,260);//left window ver
 line(340,240,380,240);//right window hor
 line(360,260,360,220);//right window ver
 setcolor(GREEN);
 circle(308,350,13);//human face at main door
 line(308,363,308,383);//human body line
 line(308,383,295,400);//left leg
 line(308,383,323,400);//right leg
 line(308,373,293,369);//left hand
 line(308,373,323,369);//right hand
 setcolor(RED);
 circle(450,50,20);//sun
 line(450,30,450,10);//up
 line(450,70,450,90);//down
 line(430,50,410,50);//left
 line(470,50,490,50);//right
 line(463,36,483,18);//upright
 line(437,64,417,82);//downleft
 line(437,36,417,18);//upleft
 line(463,64,483,82);//downright
 setcolor(WHITE);
 line(280,400,800,800);//road left part
 line(335,400,885,800);//road right part
 setcolor(BROWN);
 circle(137,360,4);//side door handle
 line(110,200,210,50);//other roof llel 1
 line(120,200,220,50);//" 2
 line(130,200,230,50);//" 3
 line(140,200,240,50);//" 4
 line(150,200,250,50);//" 5
 line(160,200,260,50);//" 6
 line(170,200,270,50);//" 7
 line(180,200,280,50);//" 8
 line(190,200,290,50);//" 9
 line(290,65,310,65);//main roof llel 1
 line(280,80,320,80);//" 2
 line(270,95,330,95);//" 3
 line(260,110,340,110);//" 4
 line(250,125,350,125);//" 5
 line(240,140,360,140);//" 6
 line(230,155,370,155);//" 7
 line(220,170,380,170);//" 8
 line(210,185,390,185);//" 9
 getch();
return 0;
}