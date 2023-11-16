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
	int a, b, n;
	cin >> a >> b >> n;
	int first = a;
	int second = b / n;
	if (b % n != 0)
		second++;
	if (second < first)
		cout << "Yes";
	else
		cout << "No";


	return 0;											// total: ~O()
}
