#include <iostream>
#include "linkedList.h"
using namespace std;

int main() {
	linkedList<char> a;
	a.insertFront('g');
	cout << a.peekFront() << endl;

	linkedList<int> b;
	b.insertFront(2);
	cout << b.peekFront() << endl;

}
