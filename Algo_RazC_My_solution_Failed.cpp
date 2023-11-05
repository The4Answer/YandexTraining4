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
#include <iomanip>
//#include <json.hpp>


using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

struct st {
	
};

int main() {
	double x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	double ang = acos((x1 * x2 + y1 * y2) / (sqrt(pow(x1, 2) + pow(y1, 2)) * sqrt(pow(x2, 2) + pow(y2, 2))));
	double rad1 = sqrt(x1 * x1 + y1 * y1);
	double rad2 = sqrt(x2 * x2 + y2 * y2);

	double ans1 = min(rad1, rad2) * ang + abs(rad1 - rad2);
	double ans2 = rad1 + rad2;

	cout << fixed << setprecision(9) << min(ans1, ans2);

	
	return 0;											// total: ~O()
}
