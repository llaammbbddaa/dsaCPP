#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "LinkedList.h"
#include <string>
using namespace std;

class HashTable {

private:
        static const int buckets = 10;
        LinkedList tables[buckets];

public:
	int hashFunction(int key);
	string search(int key);
	void insert(int key, string data);
	void remove(int key);

};


#endif
