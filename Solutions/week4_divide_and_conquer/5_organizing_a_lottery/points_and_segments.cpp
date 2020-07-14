#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int linear_searchr(const vector<int> &a, int x) {
	int low = 0, high = a.end() - a.begin() - 1, mid, cnt = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x == a[mid]) {
			for (int i = mid - 1; i >= 0; i--) {
				if (a[i] == x)	cnt++;
				else break;
			}
			return mid - cnt;
		}
		else if (x < a[mid])	high = mid - 1;
		else low = mid + 1;
	}
	return low;
}


int linear_search(const vector<int> &a, int x) {
	int low = 0, high = a.end() - a.begin() - 1, mid, cnt = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x == a[mid]) {
			for (int i = mid + 1; i < a.size(); i++) {
				if (a[i] == x)	cnt++;
				else break;
			}
			return mid + cnt + 1;
		}
		else if (x < a[mid])	high = mid - 1;
		else low = mid + 1;
	}
	return low;
}

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
	vector<int> cnt(points.size());
	//write your code here

	int n = starts.size(), flag = 0, l, r;
	sort(starts.begin(), starts.end());
	sort(ends.begin(), ends.end());
	for (int i = 0; i < points.size(); i++) {
		l = linear_search(starts, points[i]);
		r = n - linear_searchr(ends, points[i]);
		cnt[i] = l + r - n;
	}
	return cnt;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	vector<int> starts(n), ends(n);
	for (size_t i = 0; i < starts.size(); i++) {
		std::cin >> starts[i] >> ends[i];
	}
	vector<int> points(m);
	for (size_t i = 0; i < points.size(); i++) {
		std::cin >> points[i];
	}
	//use fast_count_segments
	vector<int> cnt = fast_count_segments(starts, ends, points);
	for (size_t i = 0; i < cnt.size(); i++) {
		std::cout << cnt[i] << ' ';
	}
}
