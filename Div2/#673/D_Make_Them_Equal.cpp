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
    ll n;
    cin >> n;
    vector <ll> a(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % n) {
        cout << -1 << endl;
        return;
    }
    ll val = sum / n;
    vector <array<ll, 3>> ans;
    for (int i = 2; i <= n; i++) {
        if (!(a[i] % i)) {
            ll x = a[i] / i;
            a[i] -= x * i;
            a[1] += x * i;
            ans.push_back({i, 1, x});
        }
    }
    for (int i = 2; i <= n; i++) {
        if (a[i]) {
            ll x = i - (a[i] % i);
            a[1] -= x;
            a[i] += x;
            ans.push_back({1, i, x});
            x = a[i] / i;
            a[i] -= x * i;
            a[1] += x * i;
            ans.push_back({i, 1, x});
        }
    }
    for (int i = 2; i <= n; i++) {
        ll x = val - a[i];
        a[1] -= x;
        a[i] += x;
        ans.push_back({1, i, x});
    }
    for (int i = 1; i <= n; i++) {
        assert(a[i] == val);
    }
    cout << ans.size() << endl;
    for (array <ll, 3> a : ans) {
        cout << a[0] << " " << a[1] << " " << a[2] << endl;
    }
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