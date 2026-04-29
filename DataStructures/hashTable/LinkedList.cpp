#include "LinkedList.h"
#include <string>
using namespace std;

LinkedList::LinkedList() {
	head = nullptr;
}

void LinkedList::insert(int key, string data) {
	Node *a; // traversal node
	Node *b = new Node(); // data node
	b->key = key;
	b->data = data;
	if (head != nullptr) {
		a = head;
		while (a->next != nullptr) {
			a = a->next;
		}
		a->next = b;
	}
	else {
		head = b;
	}

}

void LinkedList::remove(int key) {
	Node *a = head; // traversal node
	if (head != nullptr) {
		while (a != nullptr) {
			if (a->key == key) {
				delete a;
				break;
			}
			a = a->next;
		}
	}
}

string LinkedList::search(int key) {
        Node *a = head; // traversal node
        if (head != nullptr) {
                while (a != nullptr) {
                        if (a->key == key) {
                                return a->data;
                        }
			a = a->next;
                }
        }


	return "nada vroskie";
}
