#include <iostream>
#include <cassert>
#include <vector>
#include<algorithm>
#include <string>
#include <cmath>
using namespace std;

unsigned long long get_fibonacci_huge_naive(long long n, long long m) {
	vector <int> a(6 * m);
	a[0] = 0;
	a[1] = 1;
	unsigned int length = 0;
	for (unsigned long long int i = 2; i < 6 * m; i++) {
		a[i] = (a[i - 2] + a[i - 1]) % m;
		length++;
		if (a[i - 1] == 0 && a[i] == 1)  break;
	}
	return a[n%length];
}


int main() {
	long long n, m;
	std::cin >> n;
	//>> m;
	std::cout << get_fibonacci_huge_naive(n+2, 10) << '\n';
	return 0;
}