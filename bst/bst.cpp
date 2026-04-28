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

