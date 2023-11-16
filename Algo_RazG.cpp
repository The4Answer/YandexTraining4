//#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <ctime>
//#include <json.hpp>


using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

int n, m;
vector <vector<long long>>a;
vector<vector<long long>> sum;

bool check(int len) {
	long need = len * len;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			long long cur = 0;
			if (i - len + 1 >= 0 && j - len + 1 >= 0) {
				cur += sum[i][j];
			}
			if (i - len >= 0) {
				cur -= sum[i - len][j];
			}
			if (j - len >= 0)
				cur -= sum[i][j - len];
			if (i - len >= 0 && j - len >= 0)
				cur += sum[i - len][j - len];

			if (cur == need)
				return true;
		}
	return false;
}

int main() {
	cin >> n >> m;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		a[i].resize(m);
	}
	sum = a;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) 
			cin >> a[i][j];
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			sum[i][j] += a[i][j];
			if (i - 1 >= 0)
				sum[i][j] += sum[i - 1][j];
			if (j - 1 >= 0)
				sum[i][j] += sum[i][j - 1];
			if (i - 1 >= 0 && j - 1 >=0)
				sum[i][j] -= sum[i - 1][j - 1];
		}
	}
	int r = 1100, l = 0;
	while (r - l > 1) {
		int mid = (r + l) / 2;
		if (check(mid)) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	cout << l;
	return 0;											// total: ~O()
}
