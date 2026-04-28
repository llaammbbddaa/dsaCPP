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
