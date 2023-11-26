#
# a lOOOOOOOTTTT OOFFF small mistakes, but  I solved it .......
#here is the solution :
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

int Max = 1000000007;

vector<long long> P;
vector<long long> Hash;

int main() {
    string s;
    cin >> s;
    s = ' ' + s;
    P.resize(s.size());
    P[0] = 1;
    for (int i = 1; i < s.size(); ++i)
        P[i] = (P[i - 1] * 257) % Max;

    Hash.resize(s.size());
    Hash[0] = (s[0] - '0');
    for (int i = 1; i < s.size(); ++i) {
        Hash[i] = ((Hash[i-1] * 257) + (s[i] - '0')) % Max;
    }

    long long t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        long long l, a, b;
        cin >> l >> a >> b;
        a++, b++;
        long long first = 0;
        first = (Hash[a + l - 1] + (Hash[b - 1] * P[l])) % Max;
        long long second = 0;
        second = (Hash[b + l - 1] + (Hash[a - 1] * P[l])) % Max;

        if (first == second) {
            cout << "yes" << "\n";
        }
        else {
            cout << "no" << "\n";
        }
    }

    return 0;
}
