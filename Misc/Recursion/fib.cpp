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
