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
    ll n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector <pair <int, int>> ans;
    if (s[0][1] == '1' and s[1][0] == '1') {
        if (s[n - 1][n - 2] == '1') {
            ans.push_back({n - 1, n - 2});
        }
        if (s[n - 2][n - 1] == '1') {
            ans.push_back({n - 2, n - 1});
        }
    } else if (s[0][1] == '0' and s[1][0] == '0') {
        if (s[n - 1][n - 2] == '0') {
            ans.push_back({n - 1, n - 2});
        }
        if (s[n - 2][n - 1] == '0') {
            ans.push_back({n - 2, n - 1});
        }
    } else {
        if (s[n - 1][n - 2] == s[n - 2][n - 1]) {
            if (s[0][1] == s[n - 1][n - 2]) {
                ans.push_back({0, 1});
            } else {
                ans.push_back({1, 0});
            }
        } else {
            if (s[0][1] == s[n - 1][n - 2]) {
                ans.push_back({0, 1});
                ans.push_back({n - 2, n - 1});
            } else if (s[0][1] == s[n - 2][n - 1]) {
                ans.push_back({0, 1});
                ans.push_back({n - 1, n - 2});
            } else if (s[1][0] == s[n - 1][n - 2]) {
                ans.push_back({1, 0});
                ans.push_back({n - 2, n - 1});
            } else if (s[1][0] == s[n - 2][n - 1]) {
                ans.push_back({1, 0});
                ans.push_back({n - 1, n - 2});
            }
        }
    }

    cout << ans.size() << endl;
    for (auto it : ans) {
        cout << it.first + 1 << " " << it.second + 1 << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcases = 1;
    cin >> testcases;

    while (testcases--) {
        Solve();
    }
}