#include <iostream>
#include "Queue.h"
using namespace std;

int main() {

	Queue a;
	for (int i = 0; i < 4; i++) {
		a.push(i);
	}

	cout << a.front() << endl;
	cout << a.back() << endl;
	a.pop();
	a.pop();
	cout << a.front() << endl;
	cout << a.back() << endl;

}
