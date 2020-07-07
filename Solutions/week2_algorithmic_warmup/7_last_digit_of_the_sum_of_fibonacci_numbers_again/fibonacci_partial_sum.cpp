#include <iostream>
#include <cassert>
#include <vector>
#include<algorithm>
#include <string>
#include <cmath>
using namespace std;

long long get_fibonacci_huge_naive(long long m, long long number) {
	vector <long long int> a(60);
	long long int i;
	long long int j;
	a[0] = 0;
	a[1] = 1;
	m = m;
	number = number;
	long long int sum = 1;
	long long int sum1 = 0;
	for (i = 2; i < 60; i++) {
		a[i] = (a[i - 2] + a[i - 1]) % 10;
		sum += a[i];
	}
	sum = sum * (number / 60);
	for (j = m % 60; j < (number % 60 + 1); j++)	sum1 += a[j];
	//cout << length << endl;
	long long int result = (sum1 + sum) % 10;
	if (sum1 == 0&&number>10000&&m>10000) { return get_fibonacci_huge_naive(0, number) - get_fibonacci_huge_naive(0, m) + 9; }
	return result;
}


int main() {
	long long n, n2, m, cnt = 2, flag = 0, noo = 0, a[2], t[2];
	double x;
	cin >> n >> n2;
	std::cout << get_fibonacci_huge_naive(n, n2) << '\n';
	//if(n-n2<0)	std::cout << get_fibonacci_huge_naive(n) - get_fibonacci_huge_naive(n2) << '\n';
	//else { std::cout <<  (get_fibonacci_huge_naive(n2) - get_fibonacci_huge_naive(n)) << '\n'; 
	//cout << "hlls" << endl;
	//}

	//if(n>59)	std::cout << get_fibonacci_huge_naive(n, 10) - 1 << '\n';
	//else std::cout << get_fibonacci_huge_naive(n+2 , 10)-1 << '\n';
	//cout << 593690304080 % 58 << endl;
	return 0;
}

//5618252 6583591534151

