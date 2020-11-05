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

int n;
vector <int> a, b;

bool possible(int x) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > x) {
            sum += b[i];
        }
    }
    return sum <= x;
}

void Solve() {
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    int lo = 1, hi = 2e14, mid, ans;
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        if (possible(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
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