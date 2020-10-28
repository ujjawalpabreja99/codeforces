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
int n, k;
vector <int> a, b;

int LIS(int l, int r) {
    vector <int> lis;
    int mn = a[l - 1], mx = a[r + 1];
    for (int i = l; i <= r; i++) {
        if (mn <= a[i] and a[i] <= mx) {
            auto it = upper_bound(lis.begin(), lis.end(), a[i]);
            if (it == lis.end()) {
                lis.push_back(a[i]);
            } else {
                *it = a[i];
            }
        }
    }
    return lis.size();
}

void Solve() {
    cin >> n >> k;
    a.resize(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= i;
    }
    a[0] = -1e18, a[n + 1] = 1e18;
    if (k == 0) {
        cout << n - LIS(1, n);
        return;
    }
    b.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> b[i];
    }
    for (int i = 1; i < k; i++) {
        if (a[b[i]] < a[b[i - 1]]) {
            cout << -1;
            return;
        }
    }
    int ans = LIS(1, b[0] - 1);
    for (int i = 1; i < k; i++) {
        ans += LIS(b[i - 1] + 1, b[i] - 1);
    }
    ans += LIS(b[k - 1] + 1, n);
    cout << n - k - ans;
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