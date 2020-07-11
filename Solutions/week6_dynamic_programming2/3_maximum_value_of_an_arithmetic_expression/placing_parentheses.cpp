#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

vector <long long int> MinAndMax(long long int i, long long int j, vector <char> signs, vector<long long int> num, vector<vector<long long int> > M, vector<vector<long long int> > m) {
	vector <long long int> result(2);
	long long int Min = 100, Max = -100;
	for (long long int k = i; k < j; k++) {
		long long int a, b, c, d;
		/*
	cout << "The sign issssssssssss" << signs[k] << endl;
	cout << "Compare1 issssssssssss" << compare1[0] << " " << compare1[1] << endl;
	cout << "Compare2 issssssssssss" << compare2[0] << " " << compare2[1] << endl;
	*/
		if (signs[k] == '+') {
			a = M[i][k] + M[k + 1][j];
			b = M[i][k] + m[k + 1][j];
			c = m[i][k] + M[k + 1][j];
			d = m[i][k] + m[k + 1][j];
		}
		else if (signs[k] == '-') {
			a = M[i][k] - M[k + 1][j];
			b = M[i][k] - m[k + 1][j];
			c = m[i][k] - M[k + 1][j];
			d = m[i][k] - m[k + 1][j];
		}
		else if (signs[k] == '*') {
			a = M[i][k] * M[k + 1][j];
			b = M[i][k] * m[k + 1][j];
			c = m[i][k] * M[k + 1][j];
			d = m[i][k] * m[k + 1][j];
		}
		else {
			a = M[i][k] / M[k + 1][j];
			b = M[i][k] / m[k + 1][j];
			c = m[i][k] / M[k + 1][j];
			d = m[i][k] / m[k + 1][j];
		}

		Min = min(min(min(min(Min, a), b), c), d);
		Max = max(max(max(max(Max, a), b), c), d);

		/*
		else {
			if (signs[k] == '+') {
				Min = num[i] + num[j];
				Max = num[i] + num[j];
			}
			else if (signs[k] == '-') {
				Min = num[i] - num[j];
				Max = num[i] - num[j];
			}
			else if (signs[k] == '*') {
				Min = num[i] * num[j];
				Max = num[i] * num[j];
			}
			else {
				Min = num[i] / num[j];
				Max = num[i] / num[j];
			}
		}
	*/
	}
	result[0] = Min;
	result[1] = Max;
	return result;
}

long long int get_maximum_value(const string &exp) {
	vector <long long int> num;
	vector <char> signs;
	num.push_back(0);
	signs.push_back(0);
	long long int last = 0;
	for (long long int i = 0; i < exp.length(); i++) {
		if (exp[i] == '-' || exp[i] == '+' || exp[i] == '/' || exp[i] == '*') {
			num.push_back(stoi(exp.substr(last, i - last)));
			signs.push_back(exp[i]);
			last = i + 1;
		}
	}
	num.push_back(stoi(exp.substr(last, exp.length() - last)));
	vector<vector<long long int> > M(num.size(), vector<long long int>(num.size(), 0)), m(num.size(), vector<long long int>(num.size(), 0));
	long long int n = num.size();
	for (long long int i = 1; i < num.size(); i++) {
		m[i][i] = num[i];
		M[i][i] = num[i];
	}
	for (long long int s = 1; s <= n - 1; s++) {
		for (long long int i = 1; i < n - s; i++) {
			int j = i + s;
			vector <long long int> value = MinAndMax(i, j, signs, num, M, m);
			m[i][j] = value[0];
			M[i][j] = value[1];
		}
	}
	/*
	for (int i = 1; i < M.size(); i++) {
		for (int j = 1; j < M.size(); j++) {
			cout<<m[i][j]<<" ";
		}
		cout << endl;
	}
	for (int i = 1; i < M.size(); i++) {
		for (int j = 1; j < M.size(); j++) {
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
	*/
	return M[1][n - 1];
}

int main() {
	string s;
	std::cin >> s;
	std::cout << get_maximum_value(s) << '\n';
}