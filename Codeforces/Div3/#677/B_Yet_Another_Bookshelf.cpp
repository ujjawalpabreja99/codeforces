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
    ll si = 0, ei = n - 1;
    while (si < n and a[si] != 1) {
        si++;
    }
    while (ei >= 0 and a[ei] != 1) {
        ei--;
    }
    if (si >= ei) {
        cout << 0 << endl;
        return;
    }
    ll ans = 0;
    for (int i = si; i <= ei; i++) {
        ll j = i + 1;
        while (j <= ei and a[j] == a[i]) {
            j++;
        }
        if (a[i] == 0) {
            ans += j - i;
        }
        i = j - 1;
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