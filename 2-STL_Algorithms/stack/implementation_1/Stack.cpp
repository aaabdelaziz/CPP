#include "stack.h"



stack::stack(){
	size=10;
	tos=0;
	stk=new int[10];
}

stack::stack(int s=10,int toss){
	size=s;
	tos=toss;
	stk=new int[size];

}

stack::~stack(){

delete []stk;
}

int stack:: isFull(){


}

int stack::isEmpty(){



}

