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
    vector <pair <ll, ll>> ans;
    ll different = -1;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[0]) {
            ans.push_back({1, i + 1});
            different = i + 1;
        }
    }
    if (different == -1) {
        cout << "NO" << endl;
        return;
    }
    for (int i = 1; i < n; i++) {
        if (a[i] == a[0]) {
            ans.push_back({different, i + 1});
        }
    }
    cout << "YES" << endl;
    for (auto it : ans) {
        cout << it.first << " " << it.second << endl;
    }
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