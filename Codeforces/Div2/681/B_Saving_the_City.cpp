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
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    int n = s.size(), si = 0, ei = n - 1;
    while (si < n and s[si] == '0') {
        si++;
    }
    while (ei >= 0 and s[ei] == '0') {
        ei--;
    }
    if (si > ei) {
        cout << 0 << endl;
        return;
    }
    int ans = a;
    for (int i = si; i <= ei; i++) {
        int j = i + 1;
        while (j <= ei and s[j] == s[i]) {
            j++;
        }
        if (s[i] == '0') {
            ans += min(a, (j - i) * b);
        }
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