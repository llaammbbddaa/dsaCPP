// NOTE: NOT FUNCTIONAL

/*
the one definition rule in c++ is especially important for templates
for the most part, it requires that all class definition exist in one file
in this case, it is the header file
you cannot split it into the header file and then also its definition file
as this results in defining the template twice, which causes issues
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template <typename T>
struct Node {
	T data;
	Node<T> *next;
};

template <typename T>
class linkedList {

public:
	void insertFront(T data) {
		Node<T> *temp;
		temp = new Node;
		temp->next = head;
		temp->data = data;
		head = temp;
	}

	void insertBack(T data) {
		if (head != nullptr) {
			Node<T> *temp;
			temp->next = head;
			while (temp != nullptr && temp->next != nullptr) {
				temp = temp->next;
			}
			temp->data = data;
		}
		else {
			insertFront(data);
		}
	}

	void popFront() {
		if (a != nullptr) {
			Node<T> *temp;
			temp = a;
			a = temp->next;
			delete temp;
		}
	}

	void popBack() {
	}

	T peekFront() {
		if (a != nullptr) {
			return a->data;
		}
	}

	T peekBack() {
	}


private:
	Node<T>* head = nullptr;

};

#endif
