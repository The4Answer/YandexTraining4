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




int main()
{
    int n;

    cin >> n;

    vector<int> myints(n);

    for (int i = 0; i < n; i++)
        myints[i] = i + 1;

    do {
        for (int i = 0; i < n; i++)
            cout << myints[i] << ' ';
        cout << '\n';
    } while (next_permutation(myints.begin(), myints.end()));

    return 0;
}
