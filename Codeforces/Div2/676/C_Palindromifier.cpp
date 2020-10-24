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
    vector <pair <int, int>> ans;
    ans.push_back({0, 2});
    s = s[1] + s;
    ans.push_back({1, 2});
    string temp = s.substr(1, s.size() - 2);
    reverse(temp.begin(), temp.end());
    s = s + temp;
    ans.push_back({1, s.size() - 1});
    s = s + s[s.size() - 2];
    string t = s;
    reverse(t.begin(), t.end());
    assert(s == t);
    // cout << s << endl;
    cout << ans.size() << endl;
    for (auto it : ans) {
        cout << (it.first ? "R " : "L ") << it.second << endl;
    }
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