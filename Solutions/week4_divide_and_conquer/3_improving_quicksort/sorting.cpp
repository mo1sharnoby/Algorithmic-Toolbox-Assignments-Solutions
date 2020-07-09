#include <iostream>
#include <vector>
#include <cstdlib>
#include<algorithm>
using std::vector;
using std::swap;

vector<int> partition3(vector<int> &a, int l, int r) {
	vector<int> b(2, 0);
	int x = a[l], flag = 0, cnt = 0, joker = 0;
	int j = l;
	b[1] = j;
	for (int i = l + 1; i <= r; i++) {
		if (a[i] <= x) {
			j++;
			if (a[i] < x) {
				swap(a[i], a[j]);
				cnt++;
			}
			if (a[i] == x) {
				swap(a[i], a[j]);
				//swap(a[l + cnt], a[j]);
				b[0]--;
				flag = 1;
				joker = x;
			}
		}
	}
	if (flag == 1) {
		b[0] += j;
		b[1] = j;
		/*
		for (int i = l; i <= l + 2 + cnt; i++) {
			int x = min_element(a.begin() + i, a.begin() + j) - a.begin();
			int y = find(a.begin() + i, a.begin() + j, joker) - a.begin();
			swap(a[x], a[y]);
		}
		*/
		sort(a.begin() + l, a.begin() + j + 1);
	}
	else {
		b[0] = j;
		b[1] = j;
		swap(a[l], a[j]);
	}
	return b;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
	if (l >= r) {
		return;
	}

	int k = l + rand() % (r - l + 1);
	swap(a[l], a[k]);
	vector<int> m = partition3(a, l, r);

	randomized_quick_sort(a, l, m[0] - 1);
	randomized_quick_sort(a, m[1] + 1, r);
}

int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cin >> a[i];
	}
	randomized_quick_sort(a, 0, a.size() - 1);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cout << a[i] << ' ';
	}
}