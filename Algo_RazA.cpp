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
#include <json.hpp>


using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

struct st {
	
};



int main() {
	int n, m;
	cin >> n >> m;
	vector <int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		int min1 = a[l];
		int min2 = 100000000;
		for (int j = l + 1; j <= r; ++j) {
			if (a[j] < min1) {
				min2 = min1;
				min1 = a[j];
			}
			else if (a[j] > min1){
				min2 = a[j];
			}
		}
		if (min2 < 100000000) {
			cout << min2 << "\n";
		}
		else {
			cout << "NOT FOUND" << "\n";
		}
	}
	
	
	
	return 0;											// total: ~O()
}
