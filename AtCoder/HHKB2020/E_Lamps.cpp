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
ll power(ll x, ll p) {
    ll ans = 1;
    while (p) {
        if (p & 1) {
            ans = (ans * x) % mod;
            p--;
        }
        x = (x * x) % mod;
        p >>= 1;
    }
    return ans;
}
ll add(ll x, ll y) {
    return ((x % mod) + (y % mod)) % mod;
}
ll mul(ll x, ll y) {
    return ((x % mod) * (y % mod)) % mod;
}
ll sub(ll x, ll y) {
    return ((x % mod) - (y % mod) + mod) % mod;
}


void Solve() {
    ll n, m;
    cin >> n >> m;
    string s[n];
    ll tidy = 0;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            tidy += (s[i][j] == '.');
        }
    }
    vector <vector <ll>> a(n, vector <ll>(m));
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; ) {
            if (s[i][j] == '#') {
                i++;
                continue;
            }
            int k = i + 1, len = 1;
            while (k < n and s[k][j] == '.') {
                len++;
                k++;
            }
            while (i < k) {
                a[i][j] = len;
                i++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m;) {
            if (s[i][j] == '#') {
                j++;
                continue;
            }
            int k = j + 1, len = 1;
            while (k < m and s[i][k] == '.') {
                len++;
                k++;
            }
            while (j < k) {
                a[i][j] += len;
                j++;
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') {
                continue;
            }
            ll tot = a[i][j] - 1;
            ll ways = sub(power(2, tot), 1);
            ans = add(ans, mul(ways, power(2, tidy - tot)));
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