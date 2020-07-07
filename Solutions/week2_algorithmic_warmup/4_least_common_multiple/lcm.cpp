#include <iostream>
#include <cassert>
#include <vector>
#include<algorithm>
using namespace std;

int gcd_naive(int a, int b) {
	if (b == 0)	return a;
	else {
		int a1 = a % b;
		return gcd_naive(b, a1);
	}
}
long long lcm_naive(int a, int b) {
	int i = gcd_naive(a, b);
	unsigned long long result = a / i;
	return (long long)result*b;
}


int main() {
	int a, b;
	std::cin >> a >> b;
	std::cout << lcm_naive(a, b) << std::endl;
	return 0;
}
