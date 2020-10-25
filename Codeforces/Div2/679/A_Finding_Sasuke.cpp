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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    reverse(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        cout << (i < n / 2 ? a[i] : -a[i]) << " ";
    }
    cout << endl;
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