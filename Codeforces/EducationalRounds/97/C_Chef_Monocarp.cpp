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
int n, maxTime;
vector <int> a;
vector <vector <int>> dp;
int rec(int i, int time) {
    if (time >= maxTime) {
        return 1e18;
    }
    if (i == n) {
        return 0;
    }
    if (dp[i][time] != -1) {
        return dp[i][time];
    }
    return dp[i][time] = min(rec(i + 1, time + 1) + abs(a[i] - time), rec(i, time + 1));
}

void Solve() {
    cin >> n;
    a.resize(n);
    for (auto& i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    maxTime = 200 * n;
    dp = vector <vector <int>>(n + 1, vector <int>(maxTime + 1, -1));
    cout << rec(0, 1) << endl;
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