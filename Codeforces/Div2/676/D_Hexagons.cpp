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
    ll x, y;
    cin >> x >> y;
    ll c1, c2, c3, c4, c5, c6;
    cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;

    ll pX = min(c5 + c1, c6), pY = min(c1 + c3, c2), pXY = min(c6 + c2, c1);
    ll nX = min(c2 + c4, c3), nY = min(c4 + c6, c5), nXY = min(c3 + c5, c4);
    ll ans = 1e18;
    if (x >= 0) {
        if (y >= 0) {
            ans = abs(x) * pX + abs(y) * pY;
            if (x >= y) {
                ans = min(ans, pXY * abs(x) + abs(x - y) * nY);
                ans = min(ans, pXY * abs(y) + abs(x - y) * pX);
            } else {
                ans = min(ans, pXY * abs(x) + abs(x - y) * pY);
                ans = min(ans, pXY * abs(y) + abs(x - y) * nX);
            }
        } else {
            ans = abs(x) * pX + abs(y) * nY;
            ans = min(ans, pXY * x + abs(x - y) * nY);
            ans = min(ans, nXY * abs(y) + abs(x - y) * pX);
        }
    } else {
        if (y >= 0) {
            ans = abs(x) * nX + abs(y) * pY;
            ans = min(ans, pXY * y + abs(x - y) * nX);
            ans = min(ans, nXY * abs(x) + abs(x - y) * pY);
        } else {
            ans = abs(x) * nX + abs(y) * nY;
            if (x >= y) {
                ans = min(ans, nXY * abs(x) + abs(x - y) * nY);
                ans = min(ans, nXY * abs(y) + abs(x - y) * pX);
            } else {
                ans = min(ans, nXY * abs(x) + abs(x - y) * pY);
                ans = min(ans, nXY * abs(y) + abs(x - y) * nX);
            }
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcases = 1;
    cin >> testcases;

    while (testcases--) {
        Solve();
    }
}