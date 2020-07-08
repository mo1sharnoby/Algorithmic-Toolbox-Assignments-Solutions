#include <iostream>
#include <cassert>
#include <vector>
#include<algorithm>
#include <string>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

using std::vector;

bool sortinrev(const pair<double, int> &a, const pair<double, int> &b)
{
	return (a.first > b.first);
}


double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
	double value = 0.0, w = (double)capacity, a = 0;
	vector< pair <double, long long> > vect;
	long long max = 0, n = weights.size();
	vector<double> divsion(n);
	for (int i = 0; i < n; i++)	divsion[i] = (double)((double)values[i] / (double)weights[i]);
	for (int i = 0; i < n; i++)	vect.push_back(make_pair((double)divsion[i], weights[i]));
	sort(vect.begin(), vect.end(), sortinrev);
	for (int i = 0; i < n; i++) {
		if (w == 0)	return value;
		if (vect[i].second > w)	a = (double)w;
		else a = (double)vect[i].second;
		value = (double)value + (double)((double)a * (double)vect[i].first);
		w = (double)((double)w - (double)a);
	}
	return value;
}

int main() {
	int n;
	int capacity;
	std::cin >> n >> capacity;
	vector<int> values(n);
	vector<int> weights(n);
	for (int i = 0; i < n; i++) {
		std::cin >> values[i] >> weights[i];
	}

	double optimal_value = get_optimal_value(capacity, weights, values);

	std::cout.precision(10);
	std::cout << optimal_value << std::endl;
	return 0;
}
