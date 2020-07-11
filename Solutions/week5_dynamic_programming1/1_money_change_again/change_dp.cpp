#include <iostream>
#include<vector>
using namespace std;

int get_change(int m) {
	int coins[3] = { 1,3,4 };
	vector <int> MinNumCoins(m + 1);
	MinNumCoins[0] = 0;

	for (int mo = 1; mo <= m; mo++) {
		MinNumCoins[mo] = 100000000000000;
		for (int i = 0; i < 3; i++) {
			if (mo >= coins[i]) {
				int NumCoins = MinNumCoins[mo - coins[i]] + 1;
				if (NumCoins < MinNumCoins[mo]) {
					MinNumCoins[mo] = NumCoins;
				}
			}
		}
	}
	//write your code here
	return MinNumCoins[m];
}

int main() {
	int m;
	std::cin >> m;
	std::cout << get_change(m) << '\n';
}