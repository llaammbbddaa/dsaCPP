#include <iostream>
#include "Stack.h"
using namespace std;

int main() {

	Stack<int> a;
	a.push(1);
	a.push(2);
	cout << a.peek() << endl;
	a.pop();
	cout << a.peek() << endl;

	a.push(3);
	a.push(4);
	a.push(5);
	cout << a.peek() << endl;

	Stack<char> b;
	b.push('a');
	b.push('b');
	cout << b.peek() << endl;
	b.pop();
	cout << b.peek() << endl;

}
