#include "snake.h"
#include <stdio.h>
#define StartX 1
#define StartY 1
void initial();
int main()
{
   int x = StartX;
   int y = StartY;
   int ch;
   initial();
   box(stdscr,'|','-');
   move(x,y);
   Snake s;
   do{
      ch = getch();
	  s.moving(ch);
	  
   }while(1);
}
void initial()
{
 initscr();
 cbreak();
 noecho();
 intrflush(stdscr,false);
 keypad(stdscr,true);
 refresh();
}
 
