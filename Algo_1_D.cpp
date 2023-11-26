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

void mergeS(vector<int>& arr, int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergeS(arr, l, mid);
        mergeS(arr, mid + 1, r);


        int ind1 = 0, ind2 = 0;
        vector<int> f, s;
        for (int i = l; i <= mid; ++i) 
            f.push_back(arr[i]);
        for (int i = mid + 1; i <= r; ++i)
            s.push_back(arr[i]);

        for (int i = l; i <= r; ++i) {
            if (ind1 < f.size() && ind2 < s.size()) {
                if (f[ind1] <= s[ind2]) {
                    arr[i] = (f[ind1]);
                    ind1++;
                }
                else {
                    arr[i] = (s[ind2]);
                    ind2++;
                }
            }
            else if (ind1 < f.size()) {
                arr[i] = (f[ind1]);
                ind1++;
            }
            else {
                arr[i] = (s[ind2]);
                ind2++;
            }
        }
    }
}


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    mergeS(a, 0, n - 1);
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    return 0;
}
