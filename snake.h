#ifndef	_SNAKE_H_
#include<list>
#include<curses.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
struct Location{
	int x;
	int y;
	Location(int x,int y){
		this->x = x;
		this->y = y;
	
	}
};
enum Direction{UP,DOWN,LEFT,RIGHT};
class Food{
	public:
		Food();
		~Food();
		Location *location;
		void draw();
};
typedef list<Food*> FOOD;
typedef list<Location*> BODY;
class Snake{
	private:
		Location *base;
	public:
		BODY body;
		Snake();
		~Snake();
		Direction direct;
		Location *head;
		Location *tail;
		void moving();
		bool eat(const Food &food);
		bool strikeBody(const Location &node);
		void grow();

};
#endif
