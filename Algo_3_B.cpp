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

int inf = 1000000000;


int main()
{
	int n;
	cin >> n;
	vector < vector < pair<int, int> > > g(n);

	int s = 0; 
	int f = 0;
	cin >> s >> f;
	s--, f--;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int tmp;
			cin >> tmp;
			if (i == j || tmp < 0)
				continue;
			pair<int, int> t;
			t.first = j, t.second = tmp;
			g[i].push_back(t);
		}
	}

	vector<int> d(n, inf), p(n);
	d[s] = 0;
	vector<char> u(n);
	for (int i = 0; i < n; ++i) {
		int v = -1;
		for (int j = 0; j < n; ++j)
			if (!u[j] && (v == -1 || d[j] < d[v]))
				v = j;
		if (d[v] == inf)
			break;
		u[v] = true;

		for (size_t j = 0; j < g[v].size(); ++j) {
			int to = g[v][j].first,
				len = g[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
			}
		}
	}


	if (d[f] == inf)
		cout << -1;
	else {
		vector<int> ans;
		for (int v = f; v != s; v = p[v])
			ans.push_back(v);
		ans.push_back(s);

		reverse(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); ++i) {
			cout << ans[i] + 1 << " ";
		}
	}

    return 0;
}
