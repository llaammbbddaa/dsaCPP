# dsaCPP

## Table of Contents

- [DataStructures](#datastructures)
  - [Queue](#queue)
    - Queue.cpp
    - Queue.h
    - main.cpp
  - [Stack](#stack)
    - Stack.cpp
    - Stack.h
    - Stack.md
    - main.cpp
  - [Template](#template)
    - linkedList.h
    - main.cpp
    - pair.cpp
  - [arrayQueue](#arrayqueue)
    - Queue.cpp
    - Queue.h
    - main.cpp
  - [arrayStack](#arraystack)
    - Stack.cpp
    - Stack.h
    - main.cpp
  - [bst](#bst)
    - bst.cpp
  - [dynamicQueue](#dynamicqueue)
    - Queue.cpp
    - Queue.h
    - main.cpp
  - [dynamicStack](#dynamicstack)
    - Stack.cpp
    - Stack.h
    - main.cpp
  - [hashTable](#hashtable)
    - HashTable.cpp
    - HashTable.h
    - LinkedList.cpp
    - LinkedList.h
    - main.cpp
  - [linkedStack](#linkedstack)
    - Stack.cpp
    - Stack.h
    - main.cpp
  - [templateStack](#templatestack)
    - Stack.h
    - main.cpp
- [Misc](#misc)
  - [Recursion](#recursion)
    - fib.cpp
- README.md
- [SortingAlgorithms](#sortingalgorithms)
  - BubbleSort.cpp
  - HeapSort.cpp
  - InsertionSort.cpp
  - MergeSort.cpp
  - QuickSort.cpp


## DataStructures


### Queue


##### Queue.cpp

~~~cpp
// Queue.cpp

#include <iostream>
#include "Queue.h"
using namespace std;

Queue::Queue() {
	lenList = 4; // good starting number idk
	qList = new int[lenList];
	backIndex = -1;
}

int Queue::front() {
	if (backIndex == -1) {
		return -1;
	}
	return qList[0];
}

int Queue::back() {
	if (backIndex == -1) {
		return -1;
	}
	return qList[backIndex];
}

void Queue::push(int data) {
	if ((backIndex + 2) >= lenList) {
		increaseSize();
	}

	backIndex++;
	qList[backIndex] = data;
}

void Queue::pop() {
	if (backIndex == -1) { // cannot remove from nothing
		return;
	}
	for (int i = 0; i < backIndex; i++) {
		qList[i] = qList[i + 1]; // shifting everything over by one
	}
	backIndex--;
}

void Queue::increaseSize() {
	lenList *= 2; // double array size
	int *temp;
	temp = new int[lenList];
	for (int i = 0; i < backIndex; i++) {
		temp[i] = qList[i];
	}

	delete[] qList; // free up memory
	qList = temp;
}
~~~

##### Queue.h

~~~h
// Queue.h

#ifndef QUEUE_H
#define QUEUE_H

class Queue {

	public:
		Queue();
		int front(); // view frontmost element
		int back(); // view backmost element
		void push(int data); // add element to back
		void pop(); // delete front element
		void increaseSize(); // dynamically double array size

	private:
		int *qList;
		int lenList = 0;
		int backIndex;

};

#endif
~~~

##### main.cpp

~~~cpp
// main.cpp

#include <iostream>
#include "Queue.h"
using namespace std;

int main() {

	Queue a;
	a.push(1);
	a.push(2);
	a.push(3);
	a.pop();
	cout << "front >> " << a.front() << endl;
	cout << "back >> " << a.back() << endl;
}
~~~

### Stack


##### Stack.cpp

~~~cpp
#include <iostream>
#include "Stack.h"
using namespace std;

// adds a node to the front
void Stack::push(int data) {
	Node *a;
	a = new Node;
	a->next = head;
	a->data = data;
	head = a;
}

// removes frontmost node
void Stack::pop() {
	if (head != nullptr) { // cant pop nothing
		Node *a;
		a = head;
		head = a->next;
		delete a;
	}
}

int Stack::peek() {
	if (head != nullptr) {
		return (head->data);
	}
	return -1; // peeking at nothing
}
~~~

##### Stack.h

~~~h
#ifndef STACK_H
#define STACK_H

// implementing Node struct for use in Stack class (linked stack)
struct Node {
	int data;
	Node *next;
};

// linked stack, to the best of my ability -_-
class Stack {
	public:
		void push(int data);
		void pop();
		int peek();
	private:
		Node *head = nullptr;

};

#endif
~~~

##### Stack.md

~~~md
# Linked Stack

## main.cpp
```
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
```

## Stack.cpp
```
#include <iostream>
#include "Stack.h"
using namespace std;

// adds a node to the front
void Stack::push(int data) {
	Node *a;
	a = new Node;
	a->next = head;
	a->data = data;
	head = a;
}

// removes frontmost node
void Stack::pop() {
	if (head != nullptr) { // cant pop nothing
		Node *a;
		a = head;
		head = a->next;
		delete a;
	}
}

int Stack::peek() {
	if (head != nullptr) {
		return (head->data);
	}
	return -1; // peeking at nothing
}
```

## Stack.h
```
#ifndef STACK_H
#define STACK_H

// implementing Node struct for use in Stack class (linked stack)
struct Node {
	int data;
	Node *next;
};

// linked stack, to the best of my ability -_-
class Stack {
	public:
		void push(int data);
		void pop();
		int peek();
	private:
		Node *head = nullptr;

};

#endif
```
~~~

##### main.cpp

~~~cpp
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
~~~

### Template


##### linkedList.h

~~~h
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
~~~

##### main.cpp

~~~cpp
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
~~~

##### pair.cpp

~~~cpp
#include <iostream>
using namespace std;

template <typename A, typename B> class orderedPair {

        private:
		struct pair {
			A a;
			B b;
		};
                pair *orderedSet;
                int defaultLength = 4;
		int lastIndex = 0;


	public:
		orderedPair() { // init empty ordered pair
			orderedSet = new pair[defaultLength];
		}

		void increaseLength() { // dynamically double orderedPair size
			defaultLength *= 2;
			pair *temp;
			temp = orderedSet;
			delete[] orderedSet;
			orderedSet = new pair[defaultLength];
			for (int i = 0; i < (defaultLength / 2); i++) {
				orderedSet[i] = temp[i];
			}
			delete[] temp;
		}

		void add(A a, B b) {
			if ((lastIndex + 1) >= defaultLength) {
				increaseLength();
			}
			orderedSet[lastIndex].a = a;
			orderedSet[lastIndex].b = b;
			lastIndex++;
		}

		void display() {
			for (int i = 0; i < defaultLength; i++) {
				cout << orderedSet[i].a << ", " << orderedSet[i].b << endl;
			}
		}

};

int main() {
	orderedPair<char, char> test;
	test.add('w', 'e');
	test.add('s', 'd');
	test.display();
}
~~~

### arrayQueue


##### Queue.cpp

~~~cpp
#include <iostream>
#include "Queue.h"
using namespace std;

int Queue::front() {
	if (backIndex != -1) {
		return queueArray[0];
	}
}

int Queue::back() {
	if (backIndex != -1) {
		return queueArray[backIndex];
	}
}

void Queue::push(int data) {
	if (backIndex < 49) {
		backIndex++;
		queueArray[backIndex] = data;
	}
}

void Queue::pop() {
	if (backIndex != -1) { backIndex--; }
}
~~~

##### Queue.h

~~~h
#ifndef QUEUE_H
#define QUEUE_H

class Queue {

public:
	void pop();
	int front();
	int back();
	void push(int data);

private:
	int queueArray[50];
	int backIndex = -1;

};

#endif
~~~

##### main.cpp

~~~cpp
#include <iostream>
#include "Queue.h"
using namespace std;

int main() {

	Queue a;
	for (int i = 0; i < 4; i++) {
		a.push(i);
	}

	cout << a.front() << endl;
	cout << a.back() << endl;
	a.pop();
	a.pop();
	cout << a.front() << endl;
	cout << a.back() << endl;

}
~~~

### arrayStack


##### Stack.cpp

~~~cpp
#include <iostream>
#include "Stack.h"
using namespace std;

int Stack::peek() {
	if (topIndex != 50) {
		return stackArray[topIndex];
	}
}

void Stack::pop() {
	if (topIndex != 50) {
		topIndex++;
	}
}

void Stack::push(int data) {
	if (topIndex != 0) {
		topIndex--;
		stackArray[topIndex] = data;
	}
}
~~~

##### Stack.h

~~~h
#ifndef STACK_H
#define STACK_H

class Stack {

public:
	void push(int data);
	void pop();
	int peek();

private:
	int topIndex = 50;
	int stackArray[50]; // array of size 50

};

#endif
~~~

##### main.cpp

~~~cpp
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
~~~

### bst


##### bst.cpp

~~~cpp
#include <iostream>
using namespace std;

class Node {
public:
	Node(int data) {
		this->data = data;
		left = nullptr;
		right = nullptr;
	}

	int data;
	Node *left;
	Node *right;
};

class BinarySearchTree {

public:

	bool search(int data) { return search(data, root); }
	bool search(int data, Node *current) {
    		if (current == nullptr) {
        		return false;
    		}
    		else if (data < current->data) {
        		return search(data, current->left);
    		}
    		else if (data > current->data) {
        		return search(data, current->right);
    		}
    		else { // data == current->data
        		return true;
    		}
	}

	void insert(int data) { insert(data, root); } // overloading
	void insert(int data, Node *&current) {
		if (current == nullptr) {
			current = new Node(data);
		}
		else if (data < current->data) {
			insert(data, current->left);
		}
		else if (data > current->data) {
			insert(data, current->right);
		}
		else if (data == current->data) {
			return;
		}
	}

	void remove(int data) { remove(data, root); }
	void remove(int data, Node *&current) { // not titled delete because that is used elsewhere -_-
		if (search(data)) {
			if (data < current->data) {
				remove(data, current->left);
			}
			if (data > current->data) {
				remove(data, current->right);
			}
			if (data == current->data) { // this is the actual removal part
				childRemoval(current);
			}
		}
	}

	void childRemoval(Node *&current) { // passing it by reference so it actually gets deleted, and not a copy
                if (isLeaf(current)) {
                	delete current;
			current = nullptr;
                }
                else if (hasOne(current)) {
                	if (current->left == nullptr) {
				Node *temp = current;
				current = current->right;
				delete temp;
			}
			else {
				Node *temp = current;
				current = current->left;
				delete temp;
			} // current->right == nullptr
                }
                else if (hasTwo(current)) {
                	Node *temp;
			temp = findRightSuccessor(current);
			current->data = temp->data;
			remove(temp->data, current->right);
        	}
	}

	Node* findRightSuccessor(Node *current) {
		current = current->right;
		while (true) {
			if (current->left != nullptr) { current = current->left; }
			else { return current; }
		}
	}

	void outputOrdered() { outputOrdered(root); } // overloading for sanity
	void outputOrdered(Node *current) { // i have no idea how this works
		if (current == nullptr) {
			return;
		}
		outputOrdered(current->left);
		cout << current->data << endl;
		outputOrdered(current->right);
	}

	bool isLeaf(Node *current) { return (current->left == nullptr && current->right == nullptr); }
	bool hasOne(Node *current) { return ((current->left == nullptr && current->right != nullptr) || (current->left != nullptr && current->right == nullptr)); }
	bool hasTwo(Node *current) { return (current->left != nullptr && current->right != nullptr); }

private:
	Node *root = nullptr;

};

int main() {

	BinarySearchTree a;
	for (int i = 0; i < 10; i++) {
		a.insert(i);
	}

	a.outputOrdered();
	a.remove(3);
	a.outputOrdered();

}
~~~

### dynamicQueue


##### Queue.cpp

~~~cpp
#include <iostream>
#include "Queue.h"
using namespace std;

Queue::Queue() {
	dynamicQueue = new int[currSize];
}

int Queue::front() {
	if (backIndex != -1) {
		return dynamicQueue[0];
	}
}

int Queue::back() {
	if (backIndex != -1) {
		return dynamicQueue[backIndex];
	}
}

void Queue::pop() {
	if (backIndex != -1) { backIndex--; }
}

void Queue::push(int data) {
	backIndex++;
	if (backIndex >= currSize) { increaseSize(); }
	dynamicQueue[backIndex] = data;
}

void Queue::increaseSize() {
	currSize *= 2;
	int *tempArray;
	tempArray = new int[currSize];
	for (int i = 0; i < (currSize / 2); i++) {
		tempArray[i] = dynamicQueue[i];
	}
	delete[] dynamicQueue;
	dynamicQueue = new int[currSize];
	dynamicQueue = tempArray;
}
~~~

##### Queue.h

~~~h
#ifndef QUEUE_H
#define QUEUE_H

class Queue {

public:
	int front();
	int back();
	void pop();
	void push(int data);
	void increaseSize();
	Queue();

private:
	int currSize = 2;
	int backIndex = -1;
	int *dynamicQueue;

};


#endif
~~~

##### main.cpp

~~~cpp
#include <iostream>
#include "Queue.h"
using namespace std;

int main() {

	Queue a;
	for (int i = 0; i < 4; i++) {
		a.push(i);
	}

	cout << a.front() << endl;
	cout << a.back() << endl;
	a.pop();
	a.pop();
	cout << a.front() << endl;
	cout << a.back() << endl;

}
~~~

### dynamicStack


##### Stack.cpp

~~~cpp
#include <iostream>
#include "Stack.h"
using namespace std;

Stack::Stack() {
        dynamicStack = new int[currSize];
}

int Stack::peek() {
	if (topIndex != -1) {
		return dynamicStack[topIndex];
	}
}

void Stack::pop() {
	if (topIndex != -1) {
		topIndex--;
	}
}

void Stack::push(int data) {
	topIndex++;
	if (topIndex >= currSize) { increaseSize(); }
	dynamicStack[topIndex] = data;
}

void Stack::increaseSize() {
	currSize *= 2;
	int *tempList;
	tempList = new int[currSize];
	for (int i = 0; i < (currSize / 2); i++) {
		tempList[i] = dynamicStack[i];
	}
	delete[] dynamicStack;
	dynamicStack = new int[currSize];
	dynamicStack = tempList;
}
~~~

##### Stack.h

~~~h
#ifndef STACK_H
#define STACK_H

class Stack {

public:
	void increaseSize();
	void pop();
	int peek();
	void push(int data);
	Stack();

private:
	int *dynamicStack;
	int topIndex = -1;
	int currSize = 2; // default size, and then each time itll double
};

#endif
~~~

##### main.cpp

~~~cpp
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

	a.push(3);
	a.push(4);
	a.push(5);
	cout << a.peek() << endl;

}
~~~

### hashTable


##### HashTable.cpp

~~~cpp
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
~~~

##### HashTable.h

~~~h
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
~~~

##### LinkedList.cpp

~~~cpp
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
~~~

##### LinkedList.h

~~~h
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
~~~

##### main.cpp

~~~cpp
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
~~~

### linkedStack


##### Stack.cpp

~~~cpp
#include <iostream>
#include "Stack.h"
using namespace std;

void Stack::pop() {
	if (head != nullptr) {
		Node *a;
		a = head;
		head = a->next;
		delete a;
	}
}

int Stack::peek() {
	if (head != nullptr) {
		return head->data;
	}
}

void Stack::push(int data) {
	Node *a;
	a = new Node;
	a->data = data;
	if (head != nullptr) { a->next = head; }
	head = a;
}
~~~

##### Stack.h

~~~h
#ifndef STACK_H
#define STACK_H

struct Node {
	int data;
	Node *next;
};

class Stack {

public:
	int peek();
	void pop();
	void push(int data);

private:
	Node *head = nullptr;
};

#endif
~~~

##### main.cpp

~~~cpp
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

	a.push(3);
	a.push(4);
	a.push(5);
	cout << a.peek() << endl;

}
~~~

### templateStack


##### Stack.h

~~~h
#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {

public:
	void pop() { if (topIndex != -1) { topIndex--; } }
	T peek() { if (topIndex != -1) { return dynamicStack[topIndex]; } }
	Stack() { dynamicStack = new T[currSize]; }

	void push(T data) {
		topIndex++;
		if (topIndex >= currSize) { increaseSize(); }
		dynamicStack[topIndex] = data;
	}
	void increaseSize() {
		currSize *= 2;
		T *tempList;
		tempList = new T[currSize];
		for (int i = 0; i < (currSize / 2); i++) {
			tempList[i] = dynamicStack[i];
		}
		delete[] dynamicStack;
		dynamicStack = new T[currSize];
		dynamicStack = tempList;
	}

private:
	T *dynamicStack;
	int topIndex = -1;
	int currSize = 2; // default size, and then each time itll double
};

#endif
~~~

##### main.cpp

~~~cpp
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
~~~

## Misc


### Recursion


##### fib.cpp

~~~cpp
#include <iostream>
using namespace std;

int fib(int num) {
	if (num <= 2) {
		return 1;
	}

	return (fib(num - 1) + fib (num - 2));
}

int main() {

	for (int i = 1; i <= 10; i++) {
		cout << i << " : " << fib(i) << endl;
	}

}
~~~

### README.md

~~~md
# resources for dsa

## this repo
 - this is just supposed to be like my *"notes"*
 - i prefer to learn dsa concepts by remaking them
<br>

## youtubers
 - the cherno
 - brocode
 - michael sambol
<br>

## websites
 - geeksforgeeks
 - w3schools
<br>
~~~

## SortingAlgorithms


#### BubbleSort.cpp

~~~cpp
#include <iostream>
using namespace std;

int* bubbleSort(int *a) {
	int temp;
	for (int i = 1; i < 16; i++) {
		for (int j = 0; j < 15; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	return a;
}

int main() {

	int *a = new int[16];
	int counter = 0;
	for (int i = 15; i >= 0; i--) {
		a[counter] = i;
		counter++;
	}

	for (int i = 0; i < 16; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	a = bubbleSort(a);

	for (int i = 0; i < 16; i++) {
                cout << a[i] << " ";
        }
        cout << endl;

}
~~~

#### HeapSort.cpp

~~~cpp
// max heap, heapify, heapsort

#include <iostream>
using namespace std;

void swap(int *&array, int indexA, int indexB) { // passing by reference as we are directly editing the array
	int temp = array[indexA];
	array[indexA] = array[indexB];
	array[indexB] = temp;
}

void heapify(int *array, int index, int listSize) { // swaps children / parent if children are larger than parent, w/ left preference

	int largestIndex = index;
	int leftIndex = (2 * index) + 1;
	int rightIndex = (2 * index) + 2;

	if (leftIndex < listSize && array[largestIndex] < array[leftIndex]) { // left is larger than parent
		largestIndex = leftIndex;
	}
	if (rightIndex < listSize && array[largestIndex] < array[rightIndex]) { // right is larger than parent
		largestIndex = rightIndex;
	}

	if (largestIndex != index) { // need for swap
		swap(array, index, largestIndex);
		heapify(array, largestIndex, listSize);
	}
}


void buildMaxHeap(int *array, int listSize) { // generates max heap from array, starting from the last node from children, going to the head
	// ((listSize / 2) - 1), the last node with children
	for (int i = ((listSize / 2) - 1); i >= 0; i--) {
		heapify(array, i, listSize);
	}
}

int* heapSort(int *array, int listSize) {

	buildMaxHeap(array, listSize);

	for (int i = (listSize - 1); i >= 0; i--) {
		swap(array, 0, i);
		heapify(array, 0, i);
	}

	return array;
}

int main() {

	int *a = new int[16];
	int counter = 0;
	for (int i = 15; i >= 0; i--) {
		a[counter] = i;
		counter++;
	}

	for (int i = 0; i < 16; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	a = heapSort(a, 16);

	for (int i = 0; i < 16; i++) {
                cout << a[i] << " ";
        }
        cout << endl;

}
~~~

#### InsertionSort.cpp

~~~cpp
#include <iostream>
using namespace std;

int* insertionSort(int *a) {
	int temp;
	int j;
	for (int i = 0; i < 16; i++) {
		j = i;
		while (j > 0 && (a[j] < a[j - 1])) {
			temp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = temp;
			j--;
		}
	}

	return a;
}

int main() {

        int *a = new int[16];
        int counter = 0;
        for (int i = 15; i >= 0; i--) {
                a[counter] = i;
                counter++;
        }

        for (int i = 0; i < 16; i++) {
                cout << a[i] << " ";
        }
        cout << endl;

        a = insertionSort(a);

        for (int i = 0; i < 16; i++) {
                cout << a[i] << " ";
        }
        cout << endl;

}
~~~

#### MergeSort.cpp

~~~cpp
#include <iostream>
using namespace std;

int* merge(int *a, int *b, int n) {

	int counterA = 0;
	int counterB = counterA;
	int *c = new int[n * 2];

	while (counterA < n && counterB < n) {

		if (a[counterA] > b[counterB]) {
			c[counterA + counterB] = b[counterB];
			counterB++;
		}
		else {
			c[counterA + counterB] = a[counterA];
			counterA++;
		}
	}

	while (counterA < n) {
		c[counterA + counterB] = a[counterA];
		counterA++;
	}
	while (counterB < n) {
                c[counterA + counterB] = b[counterB];
                counterB++;
        }

	return c;

}

int* mergeSort(int *a, int n) {

        if (n == 1) { return a; } // list is already sorted

        int *b = new int[n / 2];
        int *c = new int[n / 2];

        for (int i = 0; i < n / 2; i++) {
		b[i] = a[i];
		c[i] = a[i + (n / 2)];
	}

        b = mergeSort(b, (n / 2));
	c = mergeSort(c, (n / 2));

	return merge(b, c, (n / 2));

}


int main() {

        int *a = new int[16];
        int counter = 0;
        for (int i = 15; i >= 0; i--) {
                a[counter] = i;
                counter++;
        }

        for (int i = 0; i < 16; i++) {
                cout << a[i] << " ";
        }
        cout << endl;

        a = mergeSort(a, 16);

        for (int i = 0; i < 16; i++) {
                cout << a[i] << " ";
        }
        cout << endl;

}
~~~

#### QuickSort.cpp

~~~cpp
// assume a list size of 16

#include <iostream>
using namespace std;

void display(int *a) {
        for (int i = 0; i < 16; i++) { cout << a[i] << " "; }
        cout << endl;
}

int* swap(int *a, int indexA, int indexB) {
        int temp;
        temp = a[indexA];
        a[indexA] = a[indexB];
        a[indexB] = temp;
        return a;
}

void medianOfThree(int *&a, int n) {
	int first = a[0];
	int second = a[(n / 2) - 1];
	int last = a[2 - 1];

	if (first > second && first > last) { // first biggest
		if (second > last) { a = swap(a, (n / 2) - 1, n - 1); } // second is median
	}
	else if (second > first && second > last) { // second biggest
		if (first > last) { a = swap(a, 0, n - 1); } // first is median
	}
	else { // last biggest
		if (first > second) { a = swap(a, 0, n - 1); } // first is median
	}
}

void quickSort(int *&a, int n) {

	if (n <= 1) { return; } // break case

	medianOfThree(a, n); // will set the optimal pivot to the right of the array
	int *left = new int[n];
	int *right = new int[n];
	int lCounter = 0;
	int rCounter = 0;
	for (int i = 0; i < (n - 1); i++)  { // n - 1 because we neglect the pivot
		if (a[i] < a[n - 1]) {
			left[lCounter] = a[i];
			lCounter++;
		}
		else {
			right[rCounter] = a[i];
			rCounter++;
		}
	}

	// recursion
	quickSort(left, lCounter);
	quickSort(right, rCounter);

	// reconstruct array
	for (int i = 0; i < lCounter; i++) { a[i] = left[i]; }
	a[lCounter] = a[n - 1];
	for (int i = lCounter + 1; i < n; i++) { a[i] = right[i - lCounter - 1]; }

	// dont wanna leak memory
	delete[] left;
	delete[] right;

}

int main() {

        int *a = new int[16];
        int counter = 0;
        for (int i = 15; i >= 0; i--) {
                a[counter] = i;
                counter++;
        }

        display(a);

        quickSort(a, 16);

        display(a);

}
~~~