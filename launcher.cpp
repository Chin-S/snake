#include"snake.h"
#include<unistd.h>
#include<pthread.h>
Snake snake;
FOOD foodList;
int main()
{
 void *listenKeyBoard(void *arg);
 initscr();
 box(stdscr, '|', '-');  /*draw a box*/
 keypad(stdscr,true);
 curs_set(false);
 noecho();
 pthread_t tid;
 pthread_create(&tid,NULL,listenKeyBoard,NULL);
 srand(time(NULL));
 while(1){
	 snake.moving();
	 while(foodList.size()<10){
		 Food *food =  new Food();
		 foodList.push_back(food);
	 }
	 FOOD::iterator iter = foodList.begin(),temp;
	 while(iter!=foodList.end()){
		 (**iter).draw();
		 if(snake.eat(**iter)){
			 temp = iter;
			 iter++;
			 (**temp).~Food();
			 foodList.remove(*temp);
			 snake.grow();
		 }else{
			iter++;
		 }
	 }
	 BODY::iterator b_iter = --snake.body.end();
	 while(b_iter!=snake.body.begin()){
		 if(snake.strikeBody(**b_iter--)){
			 snake.~Snake();
			 mvaddstr(12,35,"game over");
			 refresh();
			 getchar();
			 return 1;
		 }
	 }
	 usleep(1000*100);
 }

 endwin();
 return 0;
}
void *listenKeyBoard(void *arg){
	int ch;
	while(1){
		ch = getch();
		switch(ch){
			case KEY_UP:
				if (snake.direct != DOWN){
					snake.direct = UP;
				}
				break;
			case KEY_DOWN:
				if (snake.direct != UP){
					snake.direct = DOWN;
				}
				break;
			case KEY_LEFT:
				if (snake.direct != RIGHT){
					snake.direct = LEFT;
				}
				break;
			case KEY_RIGHT:
				if (snake.direct != LEFT){
					snake.direct = RIGHT;
				}
				break;
			default:
				break;
		}
		usleep(1000*10);
	}

	return NULL;
}
