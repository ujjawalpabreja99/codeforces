/**
 * Ujjawal Pabreja [cuber_coder]
 * ujjawalpabreja99@gmail.com
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl "\n"
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const ll N = 2e5 + 1;

void Solve() {
    ll n, x;
    cin >> n >> x;
    n -= 2;
    n = max(n, 0LL);
    ll ans = 1 + (n / x + (n % x != 0));
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcases = 1;
    cin >> testcases;

    while (testcases--) {
        Solve();
    }
    return 0;
}