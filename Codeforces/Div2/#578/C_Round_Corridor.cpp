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
ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
void Solve() {
    ll n, m, q;
    cin >> n >> m >> q;
    ll g = gcd(n, m);
    ll inner = n / g, outer = m / g;
    while (q--) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll r1, r2;
        if (x1 == 1 and x2 == 1) {
            r1 = (y1 + inner - 1) / inner, r2 = (y2 + inner - 1) / inner;
        } else if (x1 == 1 and x2 == 2) {
            r1 = (y1 + inner - 1) / inner, r2 = (y2 + outer - 1) / outer;
        } else if (x1 == 2 and x2 == 1) {
            r1 = (y1 + outer - 1) / outer, r2 = (y2 + inner - 1) / inner;
        } else {
            r1 = (y1 + outer - 1) / outer, r2 = (y2 + outer - 1) / outer;
        }
        cout << (r1 == r2 ? "YES" : "NO") << endl;
    }
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