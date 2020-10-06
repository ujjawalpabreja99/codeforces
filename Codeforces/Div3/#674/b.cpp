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
    ll n, m;
    cin >> n >> m;
    ll a, b, c, d;
    bool ok = false;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d;
        ok |= (b == c);
    }
    cout << ((m % 2 == 0 and ok) ? "YES" : "NO") << endl;
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