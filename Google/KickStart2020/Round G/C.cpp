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
    ll w, n;
    cin >> w >> n;
    ll a[w], prefix[w];
    for (int i = 0; i < w; i++) {
        cin >> a[i];
        a[i]--;
    }
    sort(a, a + w);
    for (int i = 0; i < w; i++) {
        prefix[i] = (i ? prefix[i - 1] + a[i] : a[i]);
    }
    ll moves = 1e18;
    for (int i = 0; i < w; i++) {
        ll l, r, curMoves, inRange, outRange;
        if (a[i] + n / 2 < n) {
            l = lower_bound(a, a + w, a[i]) - a;
            r = upper_bound(a, a + w, a[i] + n / 2) - a;
            r--;
            inRange = prefix[r] - (l ? prefix[l - 1] : 0) - (r - l + 1) * a[i];
            outRange = l * a[i] - (l ? prefix[l - 1] : 0);
            outRange += (w - (r + 1)) * (n + a[i]) - (prefix[w - 1] - prefix[r]);
        } else {
            l = lower_bound(a, a + w, a[i] - n / 2) - a;
            r = upper_bound(a, a + w, a[i]) - a;
            r--;
            inRange = (r - l + 1) * a[i] - (prefix[r] - (l ? prefix[l - 1] : 0));
            outRange = prefix[w - 1] - prefix[r] - (w - (r + 1)) * a[i];
            outRange += l * (n - a[i]) + (l ? prefix[l - 1] : 0);
        }
        moves = min(moves, inRange + outRange);
    }
    cout << moves << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testcases = 1;
    cin >> testcases;

    for (int i = 1; i <= testcases; i++) {
        cout << "Case #" << i << ": ";
        Solve();
    }
}