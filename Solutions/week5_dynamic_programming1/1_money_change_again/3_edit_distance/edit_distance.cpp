#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;

int edit_distance(const string &str1, const string &str2) {
	vector<vector<int> > v1(str1.length() + 1, vector<int>(str2.length() + 1, 0));
	vector <int> decision(3);
	int m = str1.length();
	int n = str2.length();
	v1[0][0] = 0;
	for (int i = 1; i < m + 1; i++)v1[i][0] = i;
	for (int i = 1; i < n + 1; i++)v1[0][i] = i;
	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			int insertion, deletion, match, mismatch;
			insertion = v1[i][j - 1] + 1;
			deletion = v1[i - 1][j] + 1;
			match = v1[i - 1][j - 1];
			mismatch = v1[i - 1][j - 1] + 1;
			if (str1[i - 1] == str2[j - 1]) {
				decision[0] = insertion;
				decision[1] = deletion;
				decision[2] = match;
			}
			else {
				decision[0] = insertion;
				decision[1] = deletion;
				decision[2] = mismatch;
			}

			sort(decision.begin(), decision.end());
			v1[i][j] = decision[0];
		}
	}
	return v1[m][n];
}

int main() {
	string str1;
	string str2;
	std::cin >> str1 >> str2;
	std::cout << edit_distance(str1, str2) << std::endl;
	return 0;
}