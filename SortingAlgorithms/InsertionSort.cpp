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

