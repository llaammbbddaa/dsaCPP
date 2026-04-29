#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>
using namespace std;

struct Node { // specific to hash tables
	int key;
	string data;
	Node *next = nullptr;
};

class LinkedList {

public:
	LinkedList();
	void insert(int key, string data);
	void remove(int key);
	string search(int key);

private:
	Node *head;

};

#endif
