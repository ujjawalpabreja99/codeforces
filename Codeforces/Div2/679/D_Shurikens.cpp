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
    vector <pair <char, int>> query(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> query[i].first;
        query[i].second = -1;
        if (query[i].first == '-') {
            cin >> query[i].second;
            query[i].second--;
        }
    }
    vector <ll> index(n), additions;
    ll add = 0, remove = 0, idx = -1;
    for (int i = 0; i < 2 * n; i++) {
        if (query[i].first == '-') {
            remove++;
            if (additions.empty()) {
                cout << "NO";
                return;
            } else {
                index[query[i].second] = additions.back();
                additions.pop_back();
            }
        } else {
            add++;
            additions.push_back(add);
        }
    }
    set <pair <int, int>> s;
    for (int i = 0; i < n; i++) {
        s.insert({index[i], i});
    }
    set <int> check;
    vector <ll> order;
    for (int i = 0; i < 2 * n; i++) {
        if (query[i].first == '+') {
            check.insert((*s.begin()).second);
            order.push_back((*s.begin()).second);
            s.erase(s.begin());
        } else {
            if (*check.begin() == query[i].second) {
                check.erase(check.begin());
            } else {
                cout << "NO";
                return;
            }
        }
    }
    cout << "YES" << endl;
    for (auto i : order) {
        cout << i + 1 << " ";
    }
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