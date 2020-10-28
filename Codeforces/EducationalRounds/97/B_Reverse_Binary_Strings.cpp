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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int one = 0, zero = 0;
    for (int i = 0; i < n; i++) {
        int j = i + 1;
        while (j < n and s[j] == s[i]) {
            j++;
        }
        if (s[i] == '1') {
            one += (j - i - 1);
        } else {
            zero += (j - i - 1);
        }
        i = j - 1;
    }
    cout << max(one, zero) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testcases = 1;
    cin >> testcases;

    while (testcases--) {
        Solve();
    }
}