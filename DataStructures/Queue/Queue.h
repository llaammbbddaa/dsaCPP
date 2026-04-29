// Queue.h

#ifndef QUEUE_H
#define QUEUE_H

class Queue {

	public:
		Queue();
		int front(); // view frontmost element
		int back(); // view backmost element
		void push(int data); // add element to back
		void pop(); // delete front element
		void increaseSize(); // dynamically double array size

	private:
		int *qList;
		int lenList = 0;
		int backIndex;

};

#endif
