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
    for (auto& i : a) cin >> i;
    vector <ll> freq(MAX, 0), ans(n);
    ll notPresent = 0;
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
        while (freq[notPresent]) {
            notPresent++;
        }
        ans[i] = notPresent;
    }
    for (auto i : ans) cout << i << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcases = 1;
    // cin >> testcases;

    while (testcases--) {
        Solve();
    }
}