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
const ll inf = 1e18;
ll n;
vector <array<ll, 3>> a;

int tsp(const vector<vector<int>>& cities, int pos, int visited, vector<vector<int>>& state) {
    if (visited == ((1 << cities.size()) - 1)) {
        return cities[pos][0];
    }

    if (state[pos][visited] != inf) {
        return state[pos][visited];
    }

    for (int i = 0; i < cities.size(); ++i) {
        if (i == pos || (visited & (1 << i))) {
            continue;
        }
        int distance = cities[pos][i] + tsp(cities, i, visited | (1 << i), state);
        if (distance < state[pos][visited]) {
            state[pos][visited] = distance;
        }
    }

    return state[pos][visited];
}

void Solve() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    vector <vector<int>> cities(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cities[i][j] = abs(a[i][0] - a[j][0]) + abs(a[i][1] - a[j][1]) + max(0LL, a[i][2] - a[j][2]);
        }
    }
    vector<vector<int>> state(cities.size());
    for (auto& neighbors : state) {
        neighbors = vector<int>((1 << cities.size()) - 1, inf);
    }
    cout << tsp(cities, 0, 1, state);
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