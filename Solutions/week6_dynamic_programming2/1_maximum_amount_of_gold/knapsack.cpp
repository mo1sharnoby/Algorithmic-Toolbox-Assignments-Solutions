#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int optimal_weight(int W, const vector<int> &w) {
	//write your code here
	vector<vector<int> > value(W + 1, vector<int>(w.size() + 1, 0));
	for (int i = 1; i < w.size() + 1; i++) {
		for (int we = 1; we <= W; we++) {
			value[we][i] = value[we][i - 1];
			if (w[i - 1] <= we) {
				int val = value[we - w[i - 1]][i - 1] + w[i - 1];
				if (val > value[we][i])	value[we][i] = val;
			}
		}
	}

	return value[W][w.size()];
}

int main() {
	int n, W;
	std::cin >> W >> n;
	vector<int> w(n);
	for (int i = 0; i < n; i++) {
		std::cin >> w[i];
	}
	std::cout << optimal_weight(W, w) << '\n';
}
