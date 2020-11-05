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
    int n, q, p = 15;
    cin >> n >> q;
    vector <int> a(n), prefix(n);
    iota(a.begin(), a.end(), 1);
    for (int i = 0; i < n; i++) {
        prefix[i] = (i ? prefix[i - 1] + a[i] : a[i]);
    }
    function <void(vector <int>&)> fixPrefix = [&](vector <int>& permutation) {
        int x = permutation.size();
        for (int i = 0; i < x; i++) {
            a[n - x + i] = permutation[i];
        }
        for (int i = n - x; i < n; i++) {
            prefix[i] = (i ? prefix[i - 1] + a[i] : a[i]);
        }
    };
    function <void(int, int, int)> kThPermutation = [&](int n, int k, int start) {
        vector <int> fact(p + 1, 1);
        for (int i = 1; i <= p; i++) {
            fact[i] = i * fact[i - 1];
        }
        vector <int> permutation(n, start);
        for (int i = 0; i < n; i++) {
            permutation[i] += k / fact[n - 1 - i];
            k %= fact[n - 1 - i];
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i - 1; j >= 0; j--) {
                if (permutation[j] <= permutation[i]) {
                    permutation[i]++;
                }
            }
        }
        fixPrefix(permutation);
    };
    int k = 0;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << prefix[r] - (l ? prefix[l - 1] : 0) << endl;
        } else {
            int x;
            cin >> x;
            k += x;
            kThPermutation(min(n, p), k, max(n - p + 1, 1LL));
        }
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