#include<graphics.h>
#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>
int getkey();
struct time t;
void time()
{
//       struct  time t;
 
         gettime(&t);
         printf("   The current time is: %2d:%02d:%02d.%02d",t.ti_hour, t.ti_min, t.ti_sec, t.ti_hund);
}
void date()
{
         struct date d;
 
         getdate(&d);
         printf("    DATE: %d/%d/%d" ,d.da_day, d.da_mon,d.da_year);
 
}
void main()
{
//registerbgidriver(EGAVGA_driver);
int gd,gm;
gd=DETECT;
initgraph(&gd,&gm,"..//bgi ");
cleardevice();
 
int ar,xc,yc,xr=0,yr=195,a=1,b=1,c=0,are;
void *bu,*buf;
int X=0,Y=0,s,area1;
void *buff1;
 
setcolor(3);
rectangle(80,445,159,452);
setfillstyle(1,1);
floodfill(82,447,3);
area1=imagesize(80,445,159,452);
buff1=malloc(area1);
getimage(80,445,159,452,buff1);
 
 
 int area2;
void *buffcomp;
 
rectangle(80,20,160,27);
setfillstyle(1,RED);
floodfill(85,23,3);
area2=imagesize(80,20,160,27);
buffcomp=malloc(area2);
getimage(80,20,160,27,buffcomp);
setcolor(4);
line(0,479,640,479);
 
                int area,x=325,y=325,ch,xdirn=-1,ydirn=-1,step;
                int maxx,maxy;
                void *buff;
 
                setcolor(WHITE);
                setfillstyle(SOLID_FILL,RED);
                circle(350,350,5);
                floodfill(350,350,WHITE);
 
                area=imagesize(345,345,355,355);
                buff=malloc(area);
                getimage(345,345,355,355,buff);
                putimage(345,345,buff,XOR_PUT);
                                int xd;
                                time();
                                 int hour=      t.ti_hour;
                                 int min=t.ti_min;
                                 int sec= t.ti_sec;
                                 int hund= t.ti_hund;
 
                maxx=getmaxx();
        while (1)
 
        {
 gotoxy(1,1);
        time();
        date();
                putimage(x, y, buff, XOR_PUT);
                delay(15);
                putimage(x, y, buff, XOR_PUT);
 
                x=x+(xdirn*2);
                y=y+(ydirn*3);
 
                if ( x + 10 - 1 > 640 )
                 {
                         xdirn*=-1;
                         x = 640 - 10 + 1;
                 }
                if (x < 0)
                 {
                         xdirn*=-1;
                         x = 0;
                 }
 
                        if(x>maxx-40)
                        xd=maxx-60;
                        else if(x<41)
                        xd=22;
                        else
                        xd=x;
 
                        setfillstyle(1,BLACK);
                bar(0,0,getmaxx(),28);
                putimage(xd-20,20,buffcomp,XOR_PUT);
 
 
                if ( y + 10 - 1 > 470 )
                 {
//       ydirn*=-1;
//       y = 470 - 10 + 1;
                         cleardevice();
                         outtextxy(200,200,"Sorry! You loose the game.");
                         outtextxy(250,240,"Try Again!!!");
                         gotoxy(30,8);
                         cout<<"Total Score : "<<c;
                         getch();
                         cleardevice();
                         goto tt;
                 }
                if(y==0)
                {
                         outtextxy(180,200,"Congrats! You Dominated.");
                         gotoxy(30,8);
 
                         delay(5000);
                         cleardevice();
                         getch();
                         goto tt;
 
                 }
 
                if ( getpixel(x,y)==1||getpixel(x,y)==RED )
                 {
                         sound(800);
                         delay(15);
                         sound(800);
                         delay(50);
                         ydirn*=-1;
                 }
                if( y < 0 )
                 {
                        ydirn*=-1;
                        y=0;
                 }
 
 
if( kbhit() )
{
 s=getkey();
 if(s!=1)
 {
         if(X>480)
                {
        X=480;
        putimage(160+X,445+Y,buff1,XOR_PUT);
                }
         if(X<-80)
                {
        X=-80;
        putimage(80+X,445+Y,buff1,XOR_PUT);
                }
         putimage(80+X,445+Y,buff1,XOR_PUT);
//if(s==72)
// Y+=-40;
         if(s==75)
        X+=-40;
//if(s==80)
// Y+=40;
         if(s==77)
        X+=40;
         putimage(80+X,445+Y,buff1,XOR_PUT);
//cout<<X;
        }
        if(s==1)
        {
tt:
 int hour1=     t.ti_hour;
                                 int min1=t.ti_min;
                                 int sec1= t.ti_sec;
                                 int hund1= t.ti_hund;
                                 gotoxy(getmaxx()/2,getmaxy()/2);
                                 printf("You have played for %d:%d:%d:%d",hour1-hour,min1-
 
min,sec1=sec,hund1-hund);
                                 getchar();
free(bu);
                free(buff);
                free(buff1);
                closegraph();
                exit(0);
        }
 }
}
free(buff);
free(buff1);
closegraph();
}
 
int getkey()
{
union REGS j,o;
j.h.ah=0;
int86(22,&j,&o);
return(o.h.ah);
}
