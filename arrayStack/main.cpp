#include <iostream>
#include "Stack.h"
using namespace std;

int main() {

	Stack a;
	a.push(1);
	a.push(2);
	cout << a.peek() << endl;
	a.pop();
	cout << a.peek() << endl;

}
