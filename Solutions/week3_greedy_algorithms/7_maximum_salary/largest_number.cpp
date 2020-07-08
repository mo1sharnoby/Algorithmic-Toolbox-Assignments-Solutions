#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

string largest_number(vector<string> a) {
	//write your code here
	string s = "";
	long long n = a.size();

	for (int i = 0; i < n-1 ; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (a[j + 1] + a[j] > a[j] + a[j + 1])	swap(a[j], a[j + 1]);
		}
	}
	for (int i = 0; i < n; i++)	s += a[i];
	return s;
}

int main() {
	int n;
	std::cin >> n;
	vector<string> a(n);
	for (size_t i = 0; i < a.size(); i++) {
		std::cin >> a[i];
	}
	std::cout << largest_number(a);
}


