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

bool inRange(int x, int y, pair <int, int> a) {
    return (x <= a.first and a.first <= y and x <= a.second and a.second <= y);
}

void Solve() {
    ll n, k;
    cin >> n >> k;
    string s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    if (k >= n) {
        cout << 2 * n;
        return;
    }
    pair <int, int> row[n], col[n];
    for (int i = 0; i < n; i++) {
        row[i] = {-1, -1};
        col[i] = {-1, -1};
        int si = 0, ei = n - 1;
        while (si < n and s[i][si] == 'W') {
            si++;
        }
        while (ei >= 0 and s[i][ei] == 'W') {
            ei--;
        }
        if (si <= ei) {
            row[i] = {si, ei};
        }
        si = 0, ei = n - 1;
        while (si < n and s[si][i] == 'W') {
            si++;
        }
        while (ei >= 0 and s[ei][i] == 'W') {
            ei--;
        }
        if (si <= ei) {
            col[i] = {si, ei};
        }
    }
    map <pair <int, int>, int> rows;
    for (int si = 0; si < n - k + 1; si++) {
        int curWhiteRows = 0, extra = 0;
        for (int i = 0; i < k; i++) {
            if (row[i].first == -1 or inRange(si, si + k - 1, row[i])) {
                curWhiteRows++;
            }
        }
        for (int i = k; i < n; i++) extra += (row[i].first == -1);
        for (int i = 0; i < si; i++) extra += (col[i].first == -1);
        for (int i = si + k; i < n; i++) extra += (col[i].first == -1);
        pair <int, int> idx = {0, si};
        rows[idx] = curWhiteRows + extra;
        for (int i = k; i < n; i++) {
            if (row[i - k].first == -1 or inRange(si, si + k - 1, row[i - k])) {
                curWhiteRows--;
            }
            if (row[i].first == -1 or inRange(si, si + k - 1, row[i])) {
                curWhiteRows++;
            }
            if (row[i - k].first == -1) {
                extra++;
            }
            if (row[i].first == -1) {
                extra--;
            }
            idx.first++;
            rows[idx] = curWhiteRows + extra;
        }
    }
    for (int si = 0; si < n - k + 1; si++) {
        int curWhiteCols = 0;
        for (int i = 0; i < k; i++) {
            if (col[i].first == -1 or inRange(si, si + k - 1, col[i])) {
                curWhiteCols++;
            }
        }
        pair <int, int> idx = {si, 0};
        rows[idx] += curWhiteCols;
        for (int i = k; i < n; i++) {
            if (col[i - k].first == -1 or inRange(si, si + k - 1, col[i - k])) {
                curWhiteCols--;
            }
            if (col[i].first == -1 or inRange(si, si + k - 1, col[i])) {
                curWhiteCols++;
            }
            idx.second++;
            rows[idx] += curWhiteCols;
        }
    }
    int ans = 0;
    for (auto it : rows) {
        ans = max(ans, it.second);
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