#include <iostream>

int get_change(int m) {
  //write your code here
	long long n=0;
	int m10 = 0, m5 = 0, m1 = 0;
	m10 = m / 10;
	m = m % 10;
	m5 = m / 5;
	m = m % 5;
	m1 = m ;
	n = m10 + m5 + m1;
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
