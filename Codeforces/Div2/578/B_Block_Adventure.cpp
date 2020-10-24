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
    ll n, m, k;
    cin >> n >> m >> k;
    vector <ll> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    ll prev = a[0];
    for (int i = 1; i < n; i++) {
        ll val = max(a[i] - k, 0LL);
        if (prev < val) {
            if (prev + m >= val) {
                m -= (val - prev);
            } else {
                cout << "NO" << endl;
                return;
            }
        } else {
            m += (prev - val);
        }
        prev = a[i];
    }
    cout << "YES" << endl;
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