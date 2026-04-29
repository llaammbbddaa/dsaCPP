// Queue.cpp

#include <iostream>
#include "Queue.h"
using namespace std;

Queue::Queue() {
	lenList = 4; // good starting number idk
	qList = new int[lenList];
	backIndex = -1;
}

int Queue::front() {
	if (backIndex == -1) {
		return -1;
	}
	return qList[0];
}

int Queue::back() {
	if (backIndex == -1) {
		return -1;
	}
	return qList[backIndex];
}

void Queue::push(int data) {
	if ((backIndex + 2) >= lenList) {
		increaseSize();
	}

	backIndex++;
	qList[backIndex] = data;
}

void Queue::pop() {
	if (backIndex == -1) { // cannot remove from nothing
		return;
	}
	for (int i = 0; i < backIndex; i++) {
		qList[i] = qList[i + 1]; // shifting everything over by one
	}
	backIndex--;
}

void Queue::increaseSize() {
	lenList *= 2; // double array size
	int *temp;
	temp = new int[lenList];
	for (int i = 0; i < backIndex; i++) {
		temp[i] = qList[i];
	}

	delete[] qList; // free up memory
	qList = temp;
}
