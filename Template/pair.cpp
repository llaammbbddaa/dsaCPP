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
