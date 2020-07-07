#include <iostream>
#include <cassert>
#include <vector>
#include<algorithm>
#include <string>
#include <cmath>
using namespace std;
int fibonacci_fast_lastD(long long n) {
	//vector <int> a(n+2);
	int result;
	int a = 0;
	int b = 1, p = 0;
	int i;
	for (i = 2; i <= n % 60; i++) {
		p = (a + b) % 10;
		a = b;
		b = p;
	}
	//result = a[n];
	return p;
}

int fibonacci_sum_squares_naive(long long n) {
	if (n <= 1)
		return n;
	int n1, n2;
	n1 = fibonacci_fast_lastD(n);
	n2 = fibonacci_fast_lastD(n + 1);
	string s = to_string(n1*n2);
	n = stoi(s) % 10;
	return n;
}

int main() {
	long long n = 0;
	std::cin >> n;
	std::cout << fibonacci_sum_squares_naive(n);
}



