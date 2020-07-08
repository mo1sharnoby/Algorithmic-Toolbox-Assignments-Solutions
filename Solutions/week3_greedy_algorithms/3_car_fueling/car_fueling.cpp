#include <iostream>
#include <vector>
#include<algorithm>
using std::cin;
using std::cout;
using std::vector;

int compute_min_refills(int dist, int tank, vector<int> stops) {
	// write your code here
	stops.push_back(dist);
	stops.insert(stops.begin(), 0);
	long long n = stops.size() - 2, currentRefill = 0, lastRefill = 0, numRefills = 0;
	while (currentRefill <= n) {
		lastRefill = currentRefill;
		while (currentRefill <= n && (stops[currentRefill + 1] - stops[lastRefill]) <= tank) {
			currentRefill++;
		}
		if (currentRefill == lastRefill)	return -1;
		if (currentRefill <= n)	numRefills++;
	}
	return numRefills;
}


int main() {
	int d = 0;
	cin >> d;
	int m = 0;
	cin >> m;
	int n = 0;
	cin >> n;

	vector<int> stops(n);
	for (size_t i = 0; i < n; ++i)
		cin >> stops.at(i);

	cout << compute_min_refills(d, m, stops) << "\n";

	return 0;
}
