/**
 * Written by : Ujjawal Pabreja [cuber_coder]
 * Email : ujjawalpabreja99@gmail.com
*/
#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
#define endl "\n"
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const ll MAX = 2e5 + 1;

void Solve() {
    ll n;
    cin >> n;
    vector <int> ind[n + 1], a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (ind[a[i]].size() == 0) {
            ind[a[i]].push_back(0);
        }
        ind[a[i]].push_back(i + 1);
    }
    vector <int> ans(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        if (ind[i].size() == 0) {
            continue;
        }
        ind[i].push_back(n + 1);
        int mx = 0;
        for (int j = 1; j < ind[i].size(); j++) {
            mx = max(mx, ind[i][j] - ind[i][j - 1]);
        }
        if (ans[mx] == -1) {
            ans[mx] = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i] != -1) {
            int j = i + 1;
            while (j <= n and (ans[j] == -1 or ans[j] > ans[i])) {
                ans[j] = ans[i];
                j++;
            }
            i = j - 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcases = 1;
    cin >> testcases;

    while (testcases--) {
        Solve();
    }
    return 0;
}