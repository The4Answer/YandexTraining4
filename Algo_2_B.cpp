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
	vector<int> pref(n);
	for (int i = 1; i < n; ++i) {
		int j = pref[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pref[j - 1];
		if (s[i] == s[j])
			j++;
		pref[i] = j;
	}

	cout << n - pref[n - 1];

    return 0;
}
