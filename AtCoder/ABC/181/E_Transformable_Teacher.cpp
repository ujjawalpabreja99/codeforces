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
    int n, m;
    cin >> n >> m;
    vector <int> a(n), b(m);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector <int> prefix(n, 0), suffix(n, 0);
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            prefix[i] = (i - 2 >= 0 ? prefix[i - 2] + a[i] - a[i - 1] : a[i] - a[i - 1]);
        } else {
            prefix[i] = (i - 1 >= 0 ? prefix[i - 1] : 0);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i & 1) {
            suffix[i] = (i + 2 < n ? suffix[i + 2] + a[i + 1] - a[i] : a[i + 1] - a[i]);
        } else {
            suffix[i] = (i + 1 < n ? suffix[i + 1] : 0);
        }
    }
    int ans = 1e18;
    for (int i = 0; i < m; i++) {
        int idx = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        int pre = 0, suf = 0, cur = 0;
        if (idx & 1) {
            if (idx < n) {
                suf = suffix[idx];
            }
            if (idx - 2 >= 0) {
                pre = prefix[idx - 2];
            }
            cur = abs(a[idx - 1] - b[i]);
        } else {
            if (idx + 1 < n) {
                suf = suffix[idx + 1];
            }
            if (idx - 1 >= 0) {
                pre = prefix[idx - 1];
            }
            cur = abs(a[idx] - b[i]);
        }
        ans = min(ans, pre + suf + cur);
    }

    cout << ans << endl;
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