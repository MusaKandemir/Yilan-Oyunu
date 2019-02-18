/**
* @file                     Snake.c
* @description              C dili kullanarak basit yýlan oyunu yapýmý 
* @date                     10.02.2019
* @author                   Musa Kandemir 
**/

#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
int saha[80][23]={0};
int k,l;
int kuyrukSutun[300];
int kuyrukSatir[300]; 


void gotoxy(short x, short y){
	
	HANDLE hConsoleOutput;
	COORD Cursor_Pos={x-1,y-1};
	hConsoleOutput=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput,Cursor_Pos);
}

void cerceve (int x1,int y1, int x2,int y2,int tip){
	
int i;
for(i=x1;i<=x2;i++)

   {
	saha[i][y1]=tip;
	saha[i][y2]=tip;
   
   }

for(i=y1;i<=y2;i++)

   {
	saha[x1][i]=tip;
	saha[x2][i]=tip;
   
   }


	
}


void ekranaYaz(){
	int x;
	int y;
	for( x=0;x<80;x++)
	{
		for( y=0;y<23;y++)
		{
			gotoxy(x+1,y+1);
			if(saha[x][y]==2)
			{
				printf("%c",176);
			}
		}
		
		
	}
	
	
}

int randomYem()
{
	srand(time(NULL));
	k=3+rand()%65;
    l=3+rand()%15;
	
}

void main(){
	
	randomYem();
	cerceve(0,0,79,22,2);
	ekranaYaz();
	int sx=40,sy=12;
	unsigned char tus;
	int dx=0;
	int dy=0;
	int a=0;
	int i;
	int flag=1;
	
	do
	{
		if(kbhit())
		{
			tus=getch();
			if(tus==224)
			{
				tus=getch();
				
				switch(tus){
					
					case 72: dy=-1;dx=0;
					break;
					
					case 80: dy=1;dx=0;
					break;
					
					case 77: dx=1;dy=0;	
					break;
					
				    case 75: dx=-1;dy=0;				
				}
				 
			}
			
		}
	
		sx=sx+dx;
		sy=sy+dy;
		
		if(sx>78)
		{
		 sx=2;
		}
		   
		if(sx<2)
		{
		 sx=78;
		}
	
		if(sy>22)
       {	
	   	sy=2;
       }
		if(sy<2)
		{
		 sy=22;

		}
		
		
		kuyrukSutun[0]=sx;
		kuyrukSatir[0]=sy;
		  
		for(i=1;i<=a;i++)
		{
			if(sx==kuyrukSutun[i] && sy==kuyrukSatir[i])
			{
				gotoxy(6,20); printf("---YANDINIZ---");
		

				getch();
				flag=0;
			}
			
			
		}
		
		
		
		
		gotoxy(sx,sy); printf("*");
		
		  for(i=0;i<=a;i++)
	    	{
		
		      gotoxy(kuyrukSutun[i],kuyrukSatir[i]); printf("*");  
		    }

	
		if(sx==k && sy==l)
		{
			randomYem();
			a++;
			gotoxy(2,2); printf("Puan: %d",a *10);
		}
		gotoxy(k,l); printf("A");
		Sleep(50);
		gotoxy(sx,sy); printf(" ");
			
		  for(i=0;i<=a;i++)
	    	{
		
		      gotoxy(kuyrukSutun[i],kuyrukSatir[i]); printf(" ");  
		    }
		for(i=a;i>0;i--)
		{
			kuyrukSutun[i]=kuyrukSutun[i-1];
			kuyrukSatir[i]=kuyrukSatir[i-1];
		}

	
	}while(flag==1);


}
