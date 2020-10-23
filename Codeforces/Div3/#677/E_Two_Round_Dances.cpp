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
    ll n;
    cin >> n;
    ll fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    for (int i = 1; i <= n / 2; i++) {
        fact /= i;
        fact /= i;
    }
    ll ways = 1;
    for (int i = 1; i <= n / 2 - 1; i++) {
        ways *= i;
    }
    ll ans = fact * ways * ways;
    ans /= 2;
    cout << ans << endl;
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