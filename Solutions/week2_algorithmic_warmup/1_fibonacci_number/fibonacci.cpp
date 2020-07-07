#include <iostream>
#include <cassert>
#include <vector>
#include<algorithm>
using namespace std;
int fibonacci_naive(int n) {
	if (n <= 1)
		return n;

	return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n) {
	vector <int> a;
	int result;
	a.push_back(0);
	a.push_back(1);
	int i;
	for (i = 2; i <= n; i++) {
		a.push_back(a[i - 1] + a[i - 2]);
	}
	result = a[n];
	return result;
}

void test_solution() {
	assert(fibonacci_fast(3) == 2);
	assert(fibonacci_fast(10) == 55);
	for (int n = 0; n < 20; ++n)
		assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
	int n = 0;
	std::cin >> n;

	//std::cout << fibonacci_naive(n) << '\n';
	//test_solution();
	std::cout << fibonacci_fast(n) << '\n';
	return 0;
}
