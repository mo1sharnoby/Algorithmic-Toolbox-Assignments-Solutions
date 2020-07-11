#include <numeric>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int optimal_weight(int W, vector<int> &w) {
	//write your code here
	if (W % 3 == 0) {
		for (int repeat = 1; repeat < 4; repeat++) {
			vector<vector<int> > value(W *repeat / 3 + 1, vector<int>(w.size() + 1, 0));
			for (int i = 1; i < w.size() + 1; i++) {
				for (int we = 1; we <= W * repeat / 3; we++) {
					value[we][i] = value[we][i - 1];
					if (w[i - 1] <= we) {
						int val = value[we - w[i - 1]][i - 1] + w[i - 1];
						if (val > value[we][i])	value[we][i] = val;
					}
				}
			}
			if (value[W *repeat / 3][w.size()] != W * repeat / 3) return 0;
		}
		return 1;
	}
	return 0;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> A(n);
	for (size_t i = 0; i < A.size(); ++i) {
		std::cin >> A[i];
	}
	std::cout << optimal_weight(accumulate(A.begin(), A.end(), 0), A) << '\n';
}
