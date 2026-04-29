// main.cpp

#include <iostream>
#include "Queue.h"
using namespace std;

int main() {

	Queue a;
	a.push(1);
	a.push(2);
	a.push(3);
	a.pop();
	cout << "front >> " << a.front() << endl;
	cout << "back >> " << a.back() << endl;
}
