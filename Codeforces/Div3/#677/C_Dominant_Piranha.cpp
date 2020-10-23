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
    vector <ll> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    ll mx = *max_element(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (a[i] == mx) {
            if (i + 1 < n and a[i + 1] != mx) {
                cout << i + 1 << endl;
                return;
            }
            if (i - 1 >= 0 and a[i - 1] != mx) {
                cout << i + 1 << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
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