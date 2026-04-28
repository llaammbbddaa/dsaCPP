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
