#include <iostream>
#include <bitset>
using namespace std;

int main() {
	int n = 4;
	bitset<n> foo(n);
	cout << foo;

	return 0;
}