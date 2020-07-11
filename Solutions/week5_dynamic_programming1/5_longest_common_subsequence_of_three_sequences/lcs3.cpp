#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
	//write your code here
	vector<vector<vector<int> > > v1(a.size() + 1, vector<vector<int> >(b.size() + 1, vector <int>(c.size() + 1, 0)));
	vector <int> decision(3);
	int m = a.size(), n = b.size(), o = c.size();

	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			for (int k = 1; k < o + 1; k++) {
				if (a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1])	v1[i][j][k] = v1[i - 1][j - 1][k - 1] + 1;
				else {
					int i_direction, j_direction, k_direction;
					i_direction = v1[i - 1][j][k];
					j_direction = v1[i][j - 1][k];
					k_direction = v1[i][j][k - 1];
					decision[0] = i_direction;
					decision[1] = j_direction;
					decision[2] = k_direction;
					sort(decision.begin(), decision.end());
					v1[i][j][k] = decision[2];
				}
			}
		}
	}
	return v1[m][n][o];
}

int main() {
	size_t an;
	std::cin >> an;
	vector<int> a(an);
	for (size_t i = 0; i < an; i++) {
		std::cin >> a[i];
	}
	size_t bn;
	std::cin >> bn;
	vector<int> b(bn);
	for (size_t i = 0; i < bn; i++) {
		std::cin >> b[i];
	}
	size_t cn;
	std::cin >> cn;
	vector<int> c(cn);
	for (size_t i = 0; i < cn; i++) {
		std::cin >> c[i];
	}
	std::cout << lcs3(a, b, c) << std::endl;
}
