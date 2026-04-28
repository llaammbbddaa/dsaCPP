#ifndef QUEUE_H
#define QUEUE_H

class Queue {

public:
	int front();
	int back();
	void pop();
	void push(int data);
	void increaseSize();
	Queue();

private:
	int currSize = 2;
	int backIndex = -1;
	int *dynamicQueue;

};


#endif
