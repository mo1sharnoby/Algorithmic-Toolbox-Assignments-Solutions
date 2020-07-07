#include <iostream>
#include <cassert>
#include <vector>
#include<algorithm>
using namespace std;

int fibonacci_fast(long long n) {
	vector <int> a[n];
	int result;
	a[0] = 0;
	a[1] = 1;
	int i;
	for (i = 2; i <= n; i++) {
		a[i]=(a[i - 1] + a[i - 2]) % 10;
	}
	result = a[n];
	return result;
}

int fibonacci_sum_naive(long long n) {
	if (n <= 1)	return n;
	else return fibonacci_fast(n+2)-1;
}


int main() {
	long long n = 0;
	std::cin >> n;
	std::cout << fibonacci_fast(n);
	return 0;
}

