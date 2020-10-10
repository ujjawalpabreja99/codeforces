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
    ll n, m;
    cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') {
                continue;
            }
            if (i < n - 1 and s[i + 1][j] == '.') {
                ans++;
            }
            if (j < m - 1 and s[i][j + 1] == '.') {
                ans++;
            }
        }
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcases = 1;
    // cin >> testcases;

    while (testcases--) {
        Solve();
    }
}