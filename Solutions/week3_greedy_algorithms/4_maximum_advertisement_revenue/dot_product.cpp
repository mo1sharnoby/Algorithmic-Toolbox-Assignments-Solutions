#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product(vector<int> a, vector<int> b) {
	// write your code here
	long long result = 0, n = a.size();
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());
	for (int i = 0; i < n; i++)	result += (long long)((long long)a[i] * (long long)b[i]);
	return result;
}

int main() {
	size_t n;
	std::cin >> n;
	vector<int> a(n), b(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (size_t i = 0; i < n; i++) {
		std::cin >> b[i];
	}
	std::cout << max_dot_product(a, b) << std::endl;
}