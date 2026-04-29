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
