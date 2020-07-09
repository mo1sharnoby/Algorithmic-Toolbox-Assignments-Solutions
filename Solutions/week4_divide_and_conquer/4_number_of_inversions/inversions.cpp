#include <iostream>
#include<cmath>
#include<vector>

using namespace std;
long long int swap_cnt = 0;
vector <int> Merge(vector<int> b, vector<int> c) {
	vector<int> d(c.size() + b.size());
	int b_cnt = 0, c_cnt = 0, d_cnt = 0, lol = b.size() - 1;
	while (b_cnt != b.size() && c_cnt != c.size()) {
		if (b[b_cnt] <= c[c_cnt]) {
			d[d_cnt] = b[b_cnt];
			b_cnt++;
		}
		else {
			d[d_cnt] = c[c_cnt];
			swap_cnt += lol - b_cnt;
			swap_cnt++;
			c_cnt++;
		}
		d_cnt++;
	}
	if (b_cnt == b.size()) {
		while (c_cnt != c.size()) {
			d[d_cnt] = c[c_cnt];
			c_cnt++;
			d_cnt++;
		}
	}
	else {
		while (b_cnt != b.size()) {
			d[d_cnt] = b[b_cnt];
			b_cnt++;
			d_cnt++;
		}
	}
	return d;
}
vector <int> MergeSort(vector<int> a) {
	vector<int> a_dash;
	int n = a.size(), m = n / 2;
	if (n == 1) return a;
	vector <int> b(m), c(n - m);
	for (int i = 0; i < m; i++)	b[i] = a[i];
	for (int i = m; i < n; i++)	c[i - m] = a[i];
	b = MergeSort(b);
	c = MergeSort(c);
	a_dash = Merge(b, c);
	return a_dash;
}
int main()
{
	int t, x;
	cin >> t;
	vector <int> a(t);
	for (int i = 0; i < t; i++) cin >> a[i];
	a = MergeSort(a);
	cout << swap_cnt << endl;
	//for (int i = 0; i < t; i++)cout << a[i]<<" ";
	//cout << endl;
	return 0;
}