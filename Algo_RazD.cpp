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
	string s, t;
	cin >> s >> t;
	if (s.size() != t.size())
	{
		cout << "NO";
		return 0;
	}
	map<char, int> M1;
	map<char, int> M2;
	for (int i = 0; i < s.size(); ++i) {
		M1[s[i]]++;
	}
	for (int i = 0; i < t.size(); ++i) {
		M2[t[i]]++;
	}
	for (int i = 0; i < s.size(); ++i) {
		if (M1[s[i]] != M2[s[i]])
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";


	return 0;											// total: ~O()
}
