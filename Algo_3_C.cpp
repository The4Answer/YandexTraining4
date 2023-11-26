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

long long inf = 1000000000000000000;


int main()
{
	long long n;
	cin >> n;
	vector < vector < pair<long long, long long> > > g(n);

	long long s = 0; 
	long long f = 0;
	long long k;
	cin >> k;
	for (long long i = 0; i < k; ++i) {
		long long a, b, l;
		cin >> a >> b >> l;
		a--, b--;
		pair<long long, long long> t;
		t.first = b, t.second = l;
		g[a].push_back(t);

		t.first = a, t.second = l;
		g[b].push_back(t);

	}
	cin >> s >> f;
	s--, f--;

	vector<long long> d(n, inf), p(n);
	d[s] = 0;


	set < pair<long long, long long> > q;
	q.insert(make_pair(d[s], s));
	while (!q.empty()) {
		long long v = q.begin()->second;
		q.erase(q.begin());

		for (size_t j = 0; j < g[v].size(); ++j) {
			long long to = g[v][j].first,
				len = g[v][j].second;
			if (d[v] + len < d[to]) {
				q.erase(make_pair(d[to], to));
				d[to] = d[v] + len;
				p[to] = v;
				q.insert(make_pair(d[to], to));
			}
		}
	}


	if (d[f] == inf)
		cout << -1;
	else {
		cout << d[f];
		/*vector<long long> ans;
		for (long long v = f; v != s; v = p[v])
			ans.push_back(v);
		ans.push_back(s);

		reverse(ans.begin(), ans.end());
		for (long long i = 0; i < ans.size(); ++i) {
			cout << ans[i] + 1 << " ";
		}*/
	}

    return 0;
}
