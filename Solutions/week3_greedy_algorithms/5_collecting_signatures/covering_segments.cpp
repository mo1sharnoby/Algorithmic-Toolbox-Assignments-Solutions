#include <iostream>
#include <cassert>
#include <vector>
#include<algorithm>
#include <string>
#include <cmath>
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
using std::vector;

bool sortbysec(const pair<int, int> &a,
	const pair<int, int> &b)
{
	return (a.second < b.second);
}

struct Segment {
	int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
	vector<int> points;
	vector< pair <int, int> > vect;
	long long n = segments.size();
	for (int i = 0; i < n; i++)	vect.push_back(make_pair(segments[i].start, segments[i].end));
	sort(vect.begin(), vect.end(), sortbysec);
	long long int i = 0;
	long long int j = 1;
	while (i < n) {
		long long step = i;
		while (i < n - 1 && vect[step].second >= vect[j].first && vect[step].second <= vect[j].second) { i++; j++; }
		i++;
		j++;
		points.push_back(vect[step].second);
	}
	return points;
}

int main() {
	int n;
	std::cin >> n;
	vector<Segment> segments(n);
	for (size_t i = 0; i < segments.size(); ++i) {
		std::cin >> segments[i].start >> segments[i].end;
	}
	vector<int> points = optimal_points(segments);
	std::cout << points.size() << "\n";
	for (size_t i = 0; i < points.size(); ++i) {
		std::cout << points[i] << " ";
	}
}
