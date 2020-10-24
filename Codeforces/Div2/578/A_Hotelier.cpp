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
    string s;
    cin >> s;
    set <ll> rooms;
    for (int i = 0; i < 10; i++) {
        rooms.insert(i);
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            rooms.erase(*rooms.begin());
        } else if (s[i] == 'R') {
            rooms.erase(*rooms.rbegin());
        } else {
            rooms.insert(s[i] - '0');
        }
    }
    for (int i = 0; i < 10; i++) {
        cout << !rooms.count(i);
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