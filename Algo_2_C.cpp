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
    string s;
    cin >> s;
	int n = s.length();
	vector<int> z(n);
	//ababbababb
	//0020050200
	//0123456789
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			z[i]++;

		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << z[i] << " ";
	}

    return 0;
}
