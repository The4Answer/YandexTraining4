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

struct st {
	
};

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int m = a * d + b * c;
	int n = b * d;

	for (int i = 2; i < b * d; ++i) {
		while (m % i == 0 && n % i == 0)
		{
			m /= i;
			n /= i;
		}
	}
	cout << m << " " << n;
	
	
	return 0;											// total: ~O()
}
