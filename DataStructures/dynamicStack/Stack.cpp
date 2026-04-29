#include <iostream>
#include "Stack.h"
using namespace std;

Stack::Stack() {
        dynamicStack = new int[currSize];
}

int Stack::peek() {
	if (topIndex != -1) {
		return dynamicStack[topIndex];
	}
}

void Stack::pop() {
	if (topIndex != -1) {
		topIndex--;
	}
}

void Stack::push(int data) {
	topIndex++;
	if (topIndex >= currSize) { increaseSize(); }
	dynamicStack[topIndex] = data;
}

void Stack::increaseSize() {
	currSize *= 2;
	int *tempList;
	tempList = new int[currSize];
	for (int i = 0; i < (currSize / 2); i++) {
		tempList[i] = dynamicStack[i];
	}
	delete[] dynamicStack;
	dynamicStack = new int[currSize];
	dynamicStack = tempList;
}
