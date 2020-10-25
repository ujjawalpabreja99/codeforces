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
    vector <ll> a(6);
    for (auto& i : a) {
        cin >> i;
    }
    ll n;
    cin >> n;
    vector <ll> b(n);
    vector <vector <ll>> frets(n, vector <ll>(6));
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        for (int j = 0; j < 6; j++) {
            frets[i][j] = b[i] - a[j];
        }
        sort(frets[i].begin(), frets[i].end());
    }
    priority_queue<array <int, 3>, vector<array <int, 3>>, greater<array <int, 3>>> pq;
    ll mn = 1e18, mx = -1e18, range = 1e18;
    for (int i = 0; i < n; i++) {
        pq.push({frets[i][0], i, 0});
        mn = min(mn, frets[i][0]);
        mx = max(mx, frets[i][0]);
    }
    while (!pq.empty()) {
        array <int, 3> cur = pq.top();
        pq.pop();
        int row = cur[1], col = cur[2];
        if (col == 5) {
            break;
        }
        pq.push({frets[row][col + 1], row, col + 1});
        mn = pq.top()[0];
        mx = max(mx, frets[row][col + 1]);
        if (mx - mn < range) {
            range = mx - mn;
        }
    }
    cout << range;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testcases = 1;
    // cin >> testcases;

    while (testcases--) {
        Solve();
    }
}