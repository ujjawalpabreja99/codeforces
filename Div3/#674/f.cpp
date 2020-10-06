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
const ll MAX = 2e5 + 1;
ll n, dp[MAX][4][4];
string s, t = "abc";
ll add(ll a, ll b) {
	return (a % mod + b % mod) % mod;
}
ll power(ll x, ll p) {
	ll ans = 1;
	while (p) {
		if (p & 1) {
			ans = (ans * x) % mod;
			p--;
		}
		x = (x * x) % mod;
		p >>= 1;
	}
	return ans;
}
void A(int i) {
	for (int j = 0; j < 3; j++) {
		dp[i][0][0] = add(dp[i][0][0], dp[i - 1][j][0]);
		dp[i][0][1] = add(dp[i][0][1], dp[i - 1][j][1]);
		dp[i][0][2] = add(dp[i][0][2], dp[i - 1][j][2]);
	}
}
void B(int i) {
	for (int j = 0; j < 3; j++) {
		dp[i][1][0] = add(dp[i][1][0], dp[i - 1][j][0]);
		dp[i][1][1] = add(dp[i][1][1], add(dp[i - 1][j][1], dp[i - 1][j][0]));
		dp[i][1][2] = add(dp[i][1][2], dp[i - 1][j][2]);
	}
}
void C(int i) {
	for (int j = 0; j < 3; j++) {
		dp[i][2][0] = add(dp[i][2][0], dp[i - 1][j][0]);
		dp[i][2][1] = add(dp[i][2][1], dp[i - 1][j][1]);
		dp[i][2][2] = add(dp[i][2][2], add(dp[i - 1][j][2], dp[i - 1][j][1]));
	}
}
void Solve() {
	cin >> n >> s;
	memset(dp, 0, sizeof(dp));
	ll ques = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i - 1] == 'a') {
			dp[i][0][0] = power(3, ques);
		} else if (s[i - 1] == '?') {
			dp[i][0][0] = power(3, ques);
			ques++;
		}
	}
	for (ll i = 1; i <= n; i++) {
		if (s[i - 1] == '?') {
			A(i), B(i), C(i);
		} else {
			if (s[i - 1] == 'a') {
				A(i);
			} else if (s[i - 1] == 'b') {
				B(i);
			} else {
				C(i);
			}
		}

	}
	ll ans = 0;
	for (int i = 0; i < 3; i++) {
		ans = add(ans, dp[n][i][2]);
	}
	cout << ans << endl;
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