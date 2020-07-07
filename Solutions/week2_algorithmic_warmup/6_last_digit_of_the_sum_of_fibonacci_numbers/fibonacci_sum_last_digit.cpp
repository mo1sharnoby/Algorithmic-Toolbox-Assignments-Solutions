#include <iostream>
#include <cassert>
#include <vector>
#include<algorithm>
#include <string>
#include <cmath>
using namespace std;

unsigned long long get_fibonacci_huge_naive(long long n, long long m) {
	vector <unsigned long long> a(6 * m);
	a[0] = 0;
	a[1] = 1;
	unsigned long long length = 0;
	for (unsigned long long int i = 2; i < 6 * m; i++) {
		a[i] = (a[i - 2] + a[i - 1]) % m;
		length++;
		if (a[i - 1] == 0 && a[i] == 1)  break;
	}
	length = n % 58;
	//cout << length << endl;
	return a[length];
}


int main() {
	long long n, m, cnt = 2, flag = 0, noo = 0;
	double x;
	std::cin >> n;
	m = n;
	x = (double)((double)m / (double)60);
	noo = m / 60;
	if (x - noo > 0.9)	noo++;
	cnt -= 2 * noo;
	n += cnt;
	if (get_fibonacci_huge_naive(n, 10) == 0)	cout<< 9<<endl ;
	else cout<<get_fibonacci_huge_naive(n, 10) - 1<<endl ;
	//if(n>59)	std::cout << get_fibonacci_huge_naive(n, 10) - 1 << '\n';
	//else std::cout << get_fibonacci_huge_naive(n+2 , 10)-1 << '\n';
	//cout << 593690304080 % 58 << endl;
	return 0;
}
