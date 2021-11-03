#include<stdlib.h>
#include<dos.h>
#include<conio.h>
#include<graphics.h>
#include<iostream.h>
void main()
	{
	int sl=0;
		while (sl==0)
		{
		clrscr();
		int gd=DETECT,gm,f=2;
		int lc=100,tc=50,rc=550,bc=350;
		int l1=100,r1=150,l2=500,r2=550;
		int x=525,y=325;
		char s1,s2,ch;
		initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
		outtextxy(100,50,"DODGING GAME");
		outtextxy(100,100,"W: move forward");
		outtextxy(100,150,"S: move backward");
		outtextxy(100,200,"A: move left");
		outtextxy(100,250,"D: move right");
		outtextxy(100,300,"E: exit");
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
		outtextxy(100,350,"You are the circle");
		outtextxy(100,400,"Reach the green area while dodging the squares");
		outtextxy(100,450,"--PRESS ANY KEY TO CONTINUE");
		getch();
		cleardevice();
		setfillstyle(1,4);
		bar(lc,tc,rc,bc);
		bar(l1,250,r1,300);
		bar(l2,200,r2,250);
		bar(l1,150,r1,200);
		bar(l2,100,r2,150);
			while(f!=1)
			{
			cleardevice();
			setfillstyle(1,2);
			bar(101,51,549,99);
			setfillstyle(1,4);
			rectangle(lc,tc,rc,bc);
			line(155,100,550,100);
			line(100,300,495,300);
				if(l1==lc)
					s1='+';
				else if(r1==rc)
					s1='-';
				if (s1=='+')
				{
					bar(l1,250,r1,300);
					bar(l1,150,r1,200);
					l1++;
					r1++;
				}
				else if (s1=='-')
				{
					bar(l1,250,r1,300);
					bar(l1,150,r1,200);
					l1--;
					r1--;
				}
				if(l2==lc)
					s2='+';
				else if(r2==rc)
					s2='-';
				if(s2=='+')
				{
					bar(l2,200,r2,250);
					bar(l2,100,r2,150);
					l2++;
					r2++;
				}
				else if(s2=='-')
				{
					bar(l2,200,r2,250);
					bar(l2,100,r2,150);
					l2--;
					r2--;
				}
				circle(x,y,20);
				if(kbhit())
				{
					ch=getch();
					if(ch=='w')
					{
						if(y-25==100||y-25==300)
						y++;
					y--;
					}
					if(ch=='a')
					{
						if(x-25==100)
						x++;
					x--;
					}
					if(ch=='s')
					{
						if(y+25==350||+25==300)
						y--;
					y++;
					}
					if(ch=='d')
					{
						if(x+25==550)
						x--;
					x++;
					}
					if(ch=='e')
					exit(0);
					if(x==125&&y==125||x==525&&y==325)
					y--;
					if(x==125&&y==100)
					f=1;
				}
				if((y-20<=300&&y+20>=250)||(y-20<=200&&y+20>=150))
				{
					if((l1<=x+20||l1<=x-20)&&(r1>=x+20||r1>=x-20))
					break;
				}
				if((y-20<=250&&y+20>=200)||(y-20<=150&&y+20>=100))
				{
					if((l2<=x+20||l2<=x-20)&&(r2>=x+20||r2>=x-20))
					break;
				}
				delay(27);
			}
			cleardevice();
			if(f==1)
				outtextxy(100,100,"CONGRATULATIONS!!!!! YOU WON!!!!!");
			else
				outtextxy(100,100,"SORRY YOU LOST.....");
			delay(2000);
			getch();
		}
	}