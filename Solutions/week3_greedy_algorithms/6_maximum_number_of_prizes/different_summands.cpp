#include <iostream>
#include <vector>

using std::vector;

/*
vector<int> optimal_summands(int n) {
	vector<int> saso;
	if (n == 4) {
		saso.insert(saso.begin(),3);
		saso.insert(saso.begin(), 1);
	}
	else if (n == 3) {
		saso.insert(saso.begin(), 2);
		saso.insert(saso.begin(), 1);
	}
	else if (n % 2 == 0) {
		saso.insert(saso.begin(), n/2);
		vector <int> v = optimal_summands(n / 2);
		for(int i=0;i<v.size();i++)	saso.insert(saso.begin(), 1);
	}
	else {
		saso.insert(saso.begin(), (n / 2)+1);
		optimal_summands(n / 2);
	}
	return saso;
}
*/
vector<int> optimal_summands(int n) {
	vector<int> saso;
	long long sum = 0, j = n;
	for (int i = 1; i < n; i++) {
		if (n == 2 || n == 1) break;
		if (j <= 2 * i) { saso.push_back(j); break; }
		else { saso.push_back(i); j -= i; }
	}
	if (n == 2 || n == 1)	saso.push_back(n);
	return saso;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> summands = optimal_summands(n);
	std::cout << summands.size() << '\n';
	for (size_t i = 0; i < summands.size(); ++i) {
		std::cout << summands[i] << ' ';
	}
}
