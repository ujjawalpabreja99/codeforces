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
ll n, preventOverflow = 2e14;
vector <ll> g[MAX], a;

array <int, 3> dfs(ll u, ll par) {
    vector <array <int, 3>> child;
    for (auto v : g[u]) {
        if (v != par) {
            child.push_back(dfs(v, u));
        }
    }
    if (child.size() == 0) {
        return {a[u], 1, 0};
    }
    int mx = 0, subtreeSize = 0, canFill = 0;
    for (array <int, 3> v : child) {
        mx = max(mx, v[0]);
    }
    for (array <int, 3> v : child) {
        canFill += (mx - v[0]) * v[1] + v[2];
        subtreeSize += v[1];
    }
    if (canFill >= a[u]) {
        return {mx, subtreeSize, canFill - a[u]};
    } else {
        int rem = (a[u] - canFill);
        int extra = (rem + subtreeSize - 1) / subtreeSize;
        canFill += extra * subtreeSize - a[u];
        return {mx + extra, subtreeSize, canFill};
    }
}

ll dfsBs(ll u, ll par, ll mid) {
    bool isLeaf = true;
    ll canFill = 0;
    for (auto v : g[u]) {
        if (v != par) {
            isLeaf = false;
            ll childCanFill = dfsBs(v, u, mid);
            if (childCanFill == -1) {
                return -1;
            }
            canFill += childCanFill;
            canFill = min(preventOverflow, canFill);
        }
    }
    if (isLeaf) {
        return (a[u] <= mid ? min(preventOverflow, mid - a[u]) : -1);
    } else {
        return (a[u] <= canFill ? min(preventOverflow, canFill - a[u]) : -1);
    }
}

ll binarySearch() {
    ll low = 0, high = 4e14, mid, ans;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (dfsBs(0, -1, mid) == -1) {
            low = mid + 1;
        } else {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

void Solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        ll x;
        cin >> x;
        x--;
        g[i].push_back(x);
        g[x].push_back(i);
    }
    a.resize(n);
    for (auto& i : a) {
        cin >> i;
    }
    array <int, 3> ans = dfs(0, -1);
    ll ansBs = binarySearch();
    assert(ansBs == ans[0]);
    cout << ansBs;

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testcases = 1;
    // cin >> testcases;

    while (testcases--) {
        Solve();
    }
}