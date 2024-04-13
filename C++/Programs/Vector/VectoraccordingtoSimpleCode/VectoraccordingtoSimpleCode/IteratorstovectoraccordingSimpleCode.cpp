#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> Myvector = {1,2,3,4};

	vector<int>::iterator it;

	it = Myvector.begin();

	cout << *it;

	return 0;
}