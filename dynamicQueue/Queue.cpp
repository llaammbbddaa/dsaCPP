#include <iostream>
#include "Queue.h"
using namespace std;

Queue::Queue() {
	dynamicQueue = new int[currSize];
}

int Queue::front() {
	if (backIndex != -1) {
		return dynamicQueue[0];
	}
}

int Queue::back() {
	if (backIndex != -1) {
		return dynamicQueue[backIndex];
	}
}

void Queue::pop() {
	if (backIndex != -1) { backIndex--; }
}

void Queue::push(int data) {
	backIndex++;
	if (backIndex >= currSize) { increaseSize(); }
	dynamicQueue[backIndex] = data;
}

void Queue::increaseSize() {
	currSize *= 2;
	int *tempArray;
	tempArray = new int[currSize];
	for (int i = 0; i < (currSize / 2); i++) {
		tempArray[i] = dynamicQueue[i];
	}
	delete[] dynamicQueue;
	dynamicQueue = new int[currSize];
	dynamicQueue = tempArray;
}
