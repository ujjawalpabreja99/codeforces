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
    ll n, t;
    cin >> n >> t;
    map <ll, vector <int>> m;
    ll x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        m[x].push_back(i);
    }
    vector <ll> ans(n, 0);
    for (auto it : m) {
        if (it.first * 2 == t) {
            for (int j = 0; j < it.second.size() / 2; j++) {
                ans[it.second[j]] = 1;
            }
        } else if (m.count(t - it.first)) {
            for (auto j : it.second) {
                ans[j] = 1;
            }
            m.erase(t - it.first);
        }
    }
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
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