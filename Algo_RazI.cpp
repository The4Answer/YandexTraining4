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
	stack<char> q;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
			q.push(s[i]);
		}
		else {
			char tmp = ' ';
			if (q.empty()) {
				cout << "no";
				return 0;
			}
			tmp = q.top();
			if (tmp == '(' && s[i] == ')')
				q.pop();
			else if (tmp == '{' && s[i] == '}')
				q.pop();
			else if (tmp == '[' && s[i] == ']')
				q.pop();
			else {
				cout << "no";
				return 0;
			}
		}
	}
	if (q.empty())
		cout << "yes";
	else
		cout << "no";

	return 0;											// total: ~O()
}
