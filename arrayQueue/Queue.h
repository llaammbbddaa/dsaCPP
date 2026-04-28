#ifndef QUEUE_H
#define QUEUE_H

class Queue {

public:
	void pop();
	int front();
	int back();
	void push(int data);

private:
	int queueArray[50];
	int backIndex = -1;

};

#endif
