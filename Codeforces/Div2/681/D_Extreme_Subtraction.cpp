/**
 * Written by : Ujjawal Pabreja [cuber_coder]
 * Email : ujjawalpabreja99@gmail.com
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long
#define ll long long
#define ld long double
#define endl "\n"
const int mod = 1e9 + 7;
const int MAX = 2e5 + 1;

void Solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    int available = a[0];
    for (int i = 1; i < n; i++) {
        available -= max(0LL, -1 * (a[i] - a[i - 1]));
    }
    cout << (available < 0 ? "NO" : "YES") << endl;
    // Approach 2 (https://codeforces.com/blog/entry/84298?#comment-718394)
    // vector <int> originalArr;
    // for (int i = 0; i < n; i++) {
    //     if (originalArr.empty()) {
    //         originalArr.push_back(a[i]);
    //     } else {
    //         originalArr.push_back(a[i] - a[i - 1]);
    //     }
    // }
    // for (int i = 1; i < n; i++) {
    //     originalArr[0] -= max(0LL, -1 * originalArr[i]);
    // }
    // cout << (originalArr[0] < 0 ? "NO" : "YES") << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testcases = 1;
    cin >> testcases;

    while (testcases--) {
        Solve();
    }
}