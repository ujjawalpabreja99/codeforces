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
    if (n % 3 == 0) {
        cout << n / 3 << " " << 0 << " " << 0 << endl;
    } else if (n % 3 == 1) {
        if (n >= 6) {
            cout << n / 3 - 2 << " " << 0 << " " << 1 << endl;
        } else {
            cout << -1 << endl;
        }
    } else {
        if (n >= 3) {
            cout << n / 3 - 1 << " " << 1 << " " << 0 << endl;
        } else {
            cout << -1 << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcases = 1;
    cin >> testcases;

    while (testcases--) {
        Solve();
    }
}