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

int p[10 * MAX];
// Longest prefix that is also a suffix
void LPS(string& s) {
    for (int i = 0; i < s.size(); i++) {
        p[i] = 0;
    }
    int k = 0;
    for (int i = 2; i < s.size(); i++) {
        while (k && s[k + 1] != s[i]) {
            k = p[k];
        }
        if (s[k + 1] == s[i]) {
            p[i] = ++k;
        } else {
            k = 0;
        }
    }
}

void Solve() {
    ll n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    string ans = s[0];
    for (int i = 1; i < n; i++) {
        int preLen = min(ans.size(), s[i].size());
        string compute = "^";
        for (int j = 0; j < preLen; j++) {
            compute.push_back(ans[ans.size() - 1 - j]);
        }
        compute.push_back('^');
        for (int j = 0; j < preLen; j++) {
            compute.push_back(s[i][preLen - 1 - j]);
        }
        LPS(compute);
        for (int j = p[compute.size() - 1]; j < s[i].size(); j++) {
            ans.push_back(s[i][j]);
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcases = 1;
    // cin >> testcases;

    while (testcases--) {
        Solve();
    }
}