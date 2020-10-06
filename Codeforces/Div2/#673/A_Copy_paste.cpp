/**
 * Written by : Ujjawal Pabreja [cuber_coder]
 * Email : ujjawalpabreja99@gmail.com
*/
#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
#define endl "\n"
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const ll MAX = 2e5 + 1;

void Solve() {
    ll n, k;
    cin >> n >> k;
    vector <ll> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    ll ans = 0;
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
        ans += max(k - a[i], 0LL) / a[0];
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