#include <string>
#include "LinkedList.h"
#include "HashTable.h"
using namespace std;

int HashTable::hashFunction(int key) { return key % buckets; }

string HashTable::search(int key) {
	int newIndex = hashFunction(key);
	return tables[newIndex].search(key);
}

void HashTable::insert(int key, string data) {
	int newIndex = hashFunction(key);
	tables[newIndex].insert(key, data);
}

void HashTable::remove(int key) {
	int newIndex = hashFunction(key);
	tables[newIndex].remove(key);
}
