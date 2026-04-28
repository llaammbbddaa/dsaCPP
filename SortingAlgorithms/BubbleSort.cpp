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
