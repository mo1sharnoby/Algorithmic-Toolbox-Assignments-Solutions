#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
	int current_element = 0, cnt = 0, n = a.size(), joker = 0;
	sort(a.begin(), a.end());
	cnt = count(a.begin(), a.begin() + n, a[(left + right) / 2]);
	if (cnt > n / 2) return 1;
	return -1;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cin >> a[i];
	}
	std::cout << (get_majority_element(a, 0, n) != -1) << '\n';
}