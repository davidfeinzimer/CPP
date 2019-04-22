#include <iostream>
#include <vector>
using namespace std;

int sum(vector<int> arr, int size) {
	cout << "sum( { ";
	for (int i = 0; i < arr.size(); i++) {
		cout << arr.at(i) << " ";
	}
	cout << "} , " << size;
	cout << " )" << endl;
	if (size == 0) {
		cout << "\t" << "size == 0" << endl;
		return 0;
	}
	else {
		int myReturn = sum(arr, size-1)+arr.at(size-1);
		cout << "\t" << "myReturn: " << myReturn << endl;
		return myReturn;
	}
}

int main() {
	vector<int> myVec = {12,65,23,341,62};
	int mySum = sum(myVec,myVec.size());
	cout << "Result: " << mySum << endl;
	return 0;
}
