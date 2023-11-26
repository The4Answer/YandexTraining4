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

pair<int, int> partition(vector<int> &arr, int l, int r, int x) {
    int e = l;
    int g = l;
    for (int i = l; i <= r; ++i) {
        if (arr[i] < x) {
            swap(arr[g], arr[i]);
            swap(arr[g], arr[e]);
            e++;
            g++;
        }else if (arr[i] == x) {
            swap(arr[g], arr[i]);
            g++;
        }
    }
    return make_pair(e, g);
}

void Qsort(vector<int> &arr, int l, int r) {
    if (l < r) {
        int x = l + rand() % (r - l + 1);
        pair<int, int> EG = partition(arr, l, r, arr[x]);

        Qsort(arr, l, EG.first - 1);
        Qsort(arr, EG.second, r);
    }
}


int main() {
    srand(time(NULL));
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    Qsort(a, 0, n - 1);
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";

    return 0;
}
