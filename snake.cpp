#include"snake.h"
#include<iostream>
Snake::Snake(){
	direct = RIGHT;
	head = new Location(1,1);
	tail = new Location(1,1);
	base = new Location(1,1);
	body.push_front(base);
}
Snake::~Snake(){
	BODY::iterator iter = body.begin();
	while(iter!=body.end()){
		BODY::iterator temp = iter;
		iter++;
		mvaddch((*temp)->y,(*temp)->x,32);
		delete *temp;
		body.remove(*temp);
	}
	delete head;
	head = NULL;
	delete tail;		
	tail = NULL;
}
void Snake::moving(){
	if(head->x>=79||head->x<=0||head->y>=23||head->y<=0){
		return;
	}
	switch(direct){
		case UP:
			head->y--;
			break;
		case DOWN:
			head->y++;
			break;
		case LEFT:
			head->x--;
			break;
		case RIGHT:
			head->x++;
			break;
		default:
			break;
	}
	mvaddch(head->y,head->x,79);
	mvaddch(tail->y,tail->x,32);
	refresh();
	BODY::iterator iter = --body.end();
	while(iter!=body.begin()){
		**iter = **(--iter);
	}
	*body.front() = *head;
	*tail = *body.back();
}
bool Snake::eat(const Food &food){
	return head->x==food.location->x&&head->y==food.location->y;
}
void Snake::grow(){
	Location *growNode = new Location(tail->x,tail->y);
	moving();
	body.push_back(growNode);
	mvaddch(growNode->y,growNode->x,79);
	*tail = *body.back();
	mvprintw(3,1,"%2d",body.size());
	refresh();
}
bool Snake::strikeBody(const Location &node){
	return head->x==node.x&&head->y==node.y;
}

Food::Food(){
	int x = rand()%77+2;
	int y = rand()%21+2;
	location = new Location(x,y);
}
Food::~Food(){
	mvaddch(location->y,location->x,79);
	delete location;
	location = NULL;
}
void Food::draw(){
	mvaddch(location->y,location->x,'#');
	refresh();
}
