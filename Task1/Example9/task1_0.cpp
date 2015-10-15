#include <iostream>
using namespace std;

int main() {
	for (int i = 0; i < 30; i++) {
		cout << i;
		if ((i % 3) == 0)
			cout << " three";
		if ((i % 5) == 0)
			cout << " five";
		cout << endl;
	}
	return 0;
}