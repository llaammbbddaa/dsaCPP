#include <iostream>
#include "Queue.h"
using namespace std;

int Queue::front() {
	if (backIndex != -1) {
		return queueArray[0];
	}
}

int Queue::back() {
	if (backIndex != -1) {
		return queueArray[backIndex];
	}
}

void Queue::push(int data) {
	if (backIndex < 49) {
		backIndex++;
		queueArray[backIndex] = data;
	}
}

void Queue::pop() {
	if (backIndex != -1) { backIndex--; }
}
