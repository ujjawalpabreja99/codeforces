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
    string s;
    cin >> s;
    ll n = s.size();
    ll kick = 0, ans = 0;
    for (int i = 0; i < n - 4 + 1; i++) {
        string t = s.substr(i, 4);
        if (t == "KICK") {
            kick++;
        } else if (i + 4 < n) {
            t = s.substr(i, 5);
            if (t == "START") {
                ans += kick;
            }
        }
    }
    cout << ans << endl;
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