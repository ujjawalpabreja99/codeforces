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
    ld x;
    ll manhattan = 0, chebyshev = 0;
    ld euclidean = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        manhattan += abs(x);
        euclidean += x * x;
        chebyshev = max(chebyshev, (ll)abs(x));
    }
    cout << fixed << setprecision(15);
    cout << manhattan << endl << powl(euclidean, 0.5) << endl << chebyshev;
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