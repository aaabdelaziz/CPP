/*
 * stack.h
 *
 *  Created on: Sep 1, 2018
 *      Author: AAbdelaziz
 */

#ifndef STACK_H_
#define STACK_H_

class stack{
	int tos;
	int size;
	int* stk;
public:
	stack();
	stack(int s=10,int toss);
	~stack();
	int isFull();
	int isEmpty();
    void Push(int x);
    void Pop(int x);
};

#endif /* STACK_H_ */
