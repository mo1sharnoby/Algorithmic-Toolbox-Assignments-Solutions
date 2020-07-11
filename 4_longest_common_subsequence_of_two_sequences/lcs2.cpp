#include <iostream>
#include <vector>

using namespace std;

int lcs2(vector<int> &a, vector<int> &b) {
	vector<vector<int> > v1(a.size() + 1, vector<int>(b.size() + 1, 0));
	int m = a.size();
	int n = b.size();
	v1[0][0] = 0;
	for (int i = 1; i < m + 1; i++)v1[i][0] = 0;
	for (int i = 1; i < n + 1; i++)v1[0][i] = 0;
	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (a[i - 1] == b[j - 1])	v1[i][j] = v1[i - 1][j - 1] + 1;
			else {
				if (v1[i - 1][j] > v1[i][j - 1])v1[i][j] = v1[i - 1][j];
				else v1[i][j] = v1[i][j - 1];
			}
		}
	}
	//write your code here
	
	return v1[m][n];
}

int main() {
	size_t n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	size_t m;
	std::cin >> m;
	vector<int> b(m);
	for (size_t i = 0; i < m; i++) {
		std::cin >> b[i];
	}

	std::cout << lcs2(a, b) << std::endl;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include<cmath>
#include<string>
using namespace std;

int main() {
	int t, n, k, cnt = 0;
	string s;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> k >> s;
		for (int i = 0; i < n; i++) {

		}
	}
}
