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
    array <ld, 2> a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    for (int i = 0; i < n; i++) {
        set <ld> slopes;
        for (int j = i + 1; j < n; j++) {
            ld cur;
            if (a[i][0] == a[j][0]) {
                cur = 1e18;
            } else {
                cur = (a[i][1] - a[j][1]) / (a[i][0] - a[j][0]);
            }
            if (slopes.count(cur)) {
                cout << "Yes";
                return;
            }
            slopes.insert(cur);
        }
    }
    cout << "No";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testcases = 1;
    // cin >> testcases;

    while (testcases--) {
        Solve();
    }
}