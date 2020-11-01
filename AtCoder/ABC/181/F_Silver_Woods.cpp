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

int n;
vector <pair <ld, ld>> a;
vector <int> Parent, Rank;

void init() {
    Parent.resize(n + 2);
    Rank.resize(n + 2);
    iota(Parent.begin(), Parent.end(), 0);
}

int Find(int v) {
    while (v != Parent[v]) {
        v = Parent[v];
    }
    return v;
}

void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (Rank[u] < Rank[v]) {
        Parent[u] = v;
    } else {
        Parent[v] = u;
        if (Rank[u] == Rank[v]) {
            Rank[u]++;
        }
    }
}

ld distance(pair <ld, ld> a, pair <ld, ld> b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

bool possible(ld r) {
    init();
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (distance(a[i], a[j]) <= 4.0 * r * r) {
                Union(i, j);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (abs(a[i].second - 100) <= 2.0 * r) {
            Union(n + 1, i);
        }
        if (abs(a[i].second + 100) <= 2.0 * r) {
            Union(0, i);
        }
    }
    return Find(0) != Find(n + 1);
}

void Solve() {
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin() + 1, a.end());
    ld hi = 100, lo = 0, ans;
    ll itr = 100;
    while (itr--) {
        ld mid = lo + (hi - lo) / 2;
        if (possible(mid)) {
            lo = mid + 1;
            ans = mid;
        } else {
            hi = mid - 1;
        }
    }
    cout << fixed << setprecision(20) << ans << endl;
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