#include<list>
#include<iostream>
using namespace std;
int main(){
	list<int *> l;
	int n1 = 10;
	l.push_back(&n1);
	int n2 = 9;
	l.push_back(&n2);
	int n3 = 8;
	l.push_back(&n3);
	int n4 = 7;
	l.push_back(&n4);
	list<int *>::iterator iter = --l.end();
	while(iter!=l.begin()){
		**iter = **--iter;
	}
	 **l.begin() = 11;
	iter = l.begin(); 
	while(iter!=l.end()){
		cout<<**iter++<<endl;
	
	}
	int n5 = 6;
	l.push_back(&n5);
	cout<<*l.back()<<endl;
}
