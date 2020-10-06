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
    ll n;
    cin >> n;
    ll ans = inf;
    for (int i = 1; i * i <= n; i++) {
        ll curAns = (i - 1) + ((n + i - 1) / i) - 1;
        ans = min(ans, curAns);
    }
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