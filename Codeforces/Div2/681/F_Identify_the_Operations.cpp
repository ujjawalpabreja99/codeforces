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
const int mod = 998244353;
const int MAX = 2e5 + 1;

void Solve() {
    int n, k;
    cin >> n >> k;
    vector <int> a(n + 1), b(k + 1), presentLater(n + 2, 0), ind(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ind[a[i]] = i;
    }
    for (int i = 1; i <= k; i++) {
        cin >> b[i];
        presentLater[ind[b[i]]] = 1;
    }
    presentLater[0] = presentLater[n + 1] = true;
    int ans = 1;
    for (int i = 1; i <= k; i++) {
        int idx = ind[b[i]];
        int ways = (!presentLater[idx - 1] + !presentLater[idx + 1]);
        ans *= ways;
        ans %= mod;
        presentLater[ind[b[i]]] = 0;
    }
    cout << ans << endl;
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