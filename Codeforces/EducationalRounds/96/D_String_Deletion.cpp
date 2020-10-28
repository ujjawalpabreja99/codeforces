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
    string s;
    cin >> n >> s;
    vector <int> ranges;
    for (int i = 0; i < n; i++) {
        ll j = i + 1;
        while (j < n and s[j] == s[i]) {
            j++;
        }
        ranges.push_back(j - i);
        i = j - 1;
    }
    set <int> gt;
    for (int i = 0; i < ranges.size(); i++) {
        if (ranges[i] > 1) {
            gt.insert(i);
        }
    }
    int ans = 0;
    for (int i = 0; i < ranges.size(); i++) {
        if (ranges[i] > 1) {
            ans += 1;
        } else {
            if (gt.size() and gt.lower_bound(i) != gt.end()) {
                int next = *gt.lower_bound(i);
                ans += 1;
                ranges[next]--;
                if (ranges[next] == 1) {
                    gt.erase(next);
                }
            } else {
                ans += 1;
                i++;
            }
        }
    }
    cout << ans << endl;
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