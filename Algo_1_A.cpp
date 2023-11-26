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

int partition(vector<int> arr, int l, int r, int x) {
    int mid = l - 1;
    for (int i = l; i <= r; ++i) {
        if (arr[i] < x) {
            mid++;
            swap(arr[mid], arr[i]);
        }
    }
    return mid;
}


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int x;
    cin >> x;
    //partition
    int mid = partition(a, 0, n-1, x);
    cout << mid + 1 << "\n" << n - mid -1;

    return 0;
}
