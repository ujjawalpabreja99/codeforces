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
    string s;
    cin >> s;
    if (s.size() < 3) {
        int num = stoi(s);
        reverse(s.begin(), s.end());
        int revNum = stoi(s);
        if (num % 8 == 0 or revNum % 8 == 0) {
            cout << "Yes";
        } else {
            cout << "No";
        }
        return;
    }
    int freq[10] = {};
    for (int i = 0; i < s.size(); i++) {
        freq[s[i] - '0']++;
    }
    for (int i = 0; i < 1000; i += 8) {
        int req[10] = {}, p = 3, num = i;
        while (p--) {
            req[num % 10]++;
            num /= 10;
        }
        bool ok = true;
        for (int j = 0; j < 10; j++) {
            ok &= (req[j] <= freq[j]);
        }
        if (ok) {
            cout << "Yes";
            return;
        }
    }
    cout << "No";

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