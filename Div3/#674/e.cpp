/**
 * Ujjawal Pabreja [cuber_coder]
 * ujjawalpabreja99@gmail.com
*/
#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
#define endl "\n"
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const ll N = 2e5 + 1;

void Solve() {
	ll n;
	cin >> n;
	vector <ll> a(3), b(3);
	for (auto& i : a) {
		cin >> i;
	}
	for (auto& i : b) {
		cin >> i;
	}
	ll maxWin = 0, minWin = n;
	for (int i = 0; i < 3; i++) {
		maxWin += min(a[i], b[(i + 1) % 3]);
	}
	bool ok = false;
	for (int i = 0; i < 3; i++) {
		if (a[i] - (b[i] + b[(i + 2) % 3]) >= 0) {
			ok = true;
			minWin = min(minWin, a[i] - (b[i] + b[(i + 2) % 3]));
		}
	}
	if (minWin == n and !ok) {
		minWin = 0;
	}
	cout << minWin << " " << maxWin << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcases = 1;
	// cin >> testcases;

	while (testcases--) {
		Solve();
	}
	return 0;
}