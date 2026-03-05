#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
	Stack a;
	a.push(1);
	cout << a.peek() << endl;
	a.push(2);
	a.push(3);
	a.pop();
	cout << a.peek() << endl;
}
