#include <iostream>
#include "Stack.h"
using namespace std;

int Stack::peek() {
	if (topIndex != 50) {
		return stackArray[topIndex];
	}
}

void Stack::pop() {
	if (topIndex != 50) {
		topIndex++;
	}
}

void Stack::push(int data) {
	if (topIndex != 0) {
		topIndex--;
		stackArray[topIndex] = data;
	}
}
