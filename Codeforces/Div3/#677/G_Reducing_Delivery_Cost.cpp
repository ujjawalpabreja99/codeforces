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

ll n, m, k;
vector <vector <int>> dist;
vector <array<int, 2>> g[1001];

void dijkstra(int src) {
    priority_queue <array <int, 2>, vector <array <int, 2>>, greater <array <int, 2>>> q;
    dist[src][src] = 0;
    q.push({dist[src][src], src});
    while (!q.empty()) {
        array <int, 2> cur = q.top();
        q.pop();
        int u = cur[1];
        for (auto edge : g[u]) {
            int v = edge[0];
            int wt = edge[1];
            if (dist[src][u] + wt < dist[src][v]) {
                dist[src][v] = dist[src][u] + wt;
                q.push({dist[src][v], v});
            }
        }
    }
}

void Solve() {
    cin >> n >> m >> k;
    dist.resize(n, vector <int>(n, 1e18));
    for (int i = 0; i < m; i++) {
        ll u, v, wt;
        cin >> u >> v >> wt;
        u--, v--;
        g[u].push_back({v, wt});
        g[v].push_back({u, wt});
    }
    for (int i = 0; i < n; i++) {
        dijkstra(i);
    }
    vector <array <int, 2>> routes(k);
    for (int i = 0; i < k; i++) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        routes[i] = {u, v};
    }
    ll ans = 1e18;
    for (int u = 0; u < n; u++) {
        for (auto edge : g[u]) {
            ll v = edge[0];
            ll curAns = 0;
            for (int i = 0; i < k; i++) {
                ll a = routes[i][0], b = routes[i][1];
                curAns += min({dist[a][b], dist[a][u] + dist[v][b], dist[a][v] + dist[u][b]});
            }
            ans = min(ans, curAns);
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