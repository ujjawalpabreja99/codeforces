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
	vector <ll> a(n);
	for (auto& i : a) cin >> i;
	map <ll, ll> m;
	ll sum = 0;
	vector <pair <ll, ll>> ans;
	m[sum] = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (m.count(sum)) {
			ans.push_back({m[sum], i});
		}
		m[sum] = i + 1;
	}
	if (ans.size() == 0) {
		cout << 0;
		return;
	}
	sort(ans.begin(), ans.end());
	ll ranges = 1, end = ans[0].second;
	for (auto i : ans) {
		if (i.first >= end) {
			end = i.second;
			ranges++;
		} else {
			end = min(end, i.second);
		}
	}
	cout << ranges;
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