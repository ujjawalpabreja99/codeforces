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
    ll a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    ll freq[4 * n];
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            freq[n + i - j] += a[i][j];
        }
    }
    cout << *max_element(freq, freq + 4 * n) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testcases = 1;
    cin >> testcases;

    for (int i = 1; i <= testcases; i++) {
        cout << "Case #" << i << ": ";
        Solve();
    }
}