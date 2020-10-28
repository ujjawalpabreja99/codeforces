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
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> levels[n];
    for (auto& i : a) {
        cin >> i;
    }
    int d = 0;
    levels[d++].push_back(a[0]);
    for (int i = 1; i < n; i++) {
        levels[d].push_back(a[i]);
        int j = i + 1;
        while (j < n and a[j] > a[j - 1]) {
            levels[d].push_back(a[j]);
            j++;
        }
        i = j - 1;
        d++;
    }
    if (levels[1].size() == 0) {
        cout << 0 << endl;
        return;
    }
    int ans = 0, skip = levels[0].size();
    for (int i = 1; i < d; i++) {
        int nextSkip = 0, j = i;
        while (j < min(d, i + skip)) {
            nextSkip += levels[j].size();
            j++;
        }
        skip = nextSkip;
        ans++;
        i = j - 1;
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