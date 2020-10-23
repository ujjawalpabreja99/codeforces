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
ll n, m, k;
ll a[71][71], dp[71][71][71][71];
ll rec(ll i, ll j, ll sum, ll count) {
    if (i == n) {
        return (sum ? -1e18 : 0);
    }
    if (count == m / 2 or j == m) {
        return rec(i + 1, 0, sum, 0);
    }
    if (dp[i][j][sum][count] != -1) {
        return dp[i][j][sum][count];
    }
    ll ans = -1e18;
    ans = max(ans, rec(i, j + 1, sum, count));
    ans = max(ans, a[i][j] + rec(i, j + 1, (sum % k + a[i][j] % k) % k, count + 1));
    return dp[i][j][sum][count] = ans;
}
void Solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0, 0, 0);
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