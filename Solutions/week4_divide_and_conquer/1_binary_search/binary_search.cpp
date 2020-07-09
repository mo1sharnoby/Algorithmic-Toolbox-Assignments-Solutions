#include <iostream>
#include<string>
#include<vector>
using namespace std;

int linear_search(const vector<int> &a, int x) {
	int low = 0, high = a.end() - a.begin() - 1, mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x == a[mid])	return mid;
		else if (x < a[mid])	high = mid - 1;
		else low = mid + 1;
	}
	return -1;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); i++) {
		std::cin >> a[i];
	}
	int m;
	std::cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; ++i) {
		std::cin >> b[i];
	}
	for (int i = 0; i < m; ++i) {
		//replace with the call to binary_search when implemented
		std::cout << linear_search(a, b[i]) << ' ';
	}
}