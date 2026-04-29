#include <iostream>
#include "LinkedList.h"
#include "HashTable.h"
#include <string>
using namespace std;

int main() {

	HashTable a;
	a.insert(1, "apple");
	a.insert(2, "banana");
	a.insert(11, "carrot");

	for (int i = 0; i < 12; i++) { cout << a.search(i) << endl; }

}
