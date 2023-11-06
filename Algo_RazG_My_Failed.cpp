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
vector <vector<int>>a;
vector<vector<int>> iS;
vector<vector<int>> jS;

bool check(int i, int j, int len) {
	int up = 0, left = 0, right = 0, down = 0;
	up = iS[i][j + len] - iS[i][j];
	left = jS[i + len][j] - jS[i][j];
	right = jS[i + len][j + len] - jS[i][j + len];
	down = iS[i + len][j + len] - iS[i + len][j];
	if (left == len && up == left && left == right && right == down)
		return true;
	return false;
}

int main() {
	cin >> n >> m;
	a.resize(n);
	iS.resize(n);
	jS.resize(n);
	for (int i = 0; i < n; ++i) {
		a[i].resize(m);
		iS[i].resize(m, 0);
		jS[i].resize(m, 0);
	}
	bool isOne = false;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			/*if (!isOne && a[i][j] == 1)
				isOne = true;*/
		}

	//prep
	for (int i = 0; i < n; ++i) {
		iS[i][0] = a[i][0];
		for (int j = 1; j < m; ++j)
			iS[i][j] = iS[i][j - 1] + a[i][j];
	}
	for (int j = 0; j < m; ++j) {
		jS[0][j] = a[0][j];
		for (int i = 1; i < n; ++i)
			jS[i][j] = jS[i - 1][j] + a[i][j];
	}	

	int ans = 0;
	for (int side = 1; side <= min(n, m); ++side) {
		for (int i = 0; i < n; ++i) {
			if (i + side >= n)
				break;
			for (int j = 0; j < m; ++j) {
				if (j + side >= m)
					break;
				if (check(i, j, side)) {
					ans = side;
				}
			}
		}
	}
	/*if (ans == 0 && isOne) 
		cout << 1;
	else */if (ans == 0) 
		cout << 0;
	else
		cout << ans + 1;



	return 0;											// total: ~O()
}
