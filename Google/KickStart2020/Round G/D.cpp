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
ld tot = 0;
map <ll, ll> freq;
void rec(vector <ll> a, ll score) {
    if (a.size() == 2) {
        score += a[0] + a[1];
        freq[score]++;
        tot++;
        return;
    }
    for (int i = 0; i < a.size() - 1; i++) {
        vector <ll> next;
        ll nextScore = score;
        for (int j = 0; j < a.size(); j++) {
            if (i == j) {
                next.push_back(a[j] + a[j + 1]);
                nextScore += (a[j] + a[j + 1]);
                j++;
            } else {
                next.push_back(a[j]);
            }
        }
        rec(next, nextScore);
    }
}

void Solve() {
    tot = 0;
    freq.clear();
    ll n;
    cin >> n;
    vector <ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    rec(a, 0);
    ld ans = 0;
    for (auto it : freq) {
        cout << it.first << " " << it.second << endl;
        ans += (it.first * it.second);
    }
    ans /= tot;
    cout << fixed << setprecision(15) << ans << endl;
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