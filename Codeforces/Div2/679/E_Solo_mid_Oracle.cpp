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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > b * c) {
        cout << -1 << endl;
        return;
    }
    ll t = min(c, a / (b * d));
    ll ans = a * (t + 1) - ((t * (t + 1)) / 2) * b * d;
    cout << ans << endl;
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