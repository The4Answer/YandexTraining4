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


int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	int cur = 0;
	vector <int> ans(n, 0);
	for (int i = 1; i < n; ++i)
		cur += a[i] - a[0];
	ans[0] = cur;

	for (int i = 1; i < n; ++i) {
		if (n - i - 1 > 0)
			cur -= (n - i - 1) * (a[i] - a[i - 1]);
		cur += (i - 1) * (a[i] - a[i - 1]);
		ans[i] = cur;
	}
	for (int i = 0; i < n; ++i)
		cout << ans[i] << " ";

	return 0;											// total: ~O()
}
