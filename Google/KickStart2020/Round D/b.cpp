/*
	Nishant Singh
	nishant.ns19
*/
#include <bits/stdc++.h>
#include <functional> 
#include <iostream> 
// ******** Big Integer ********
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
// #define ll1024  int1024_t
// ******** Big Integer ********
// ******** Using PBDS ********
// #include <ext/pb_ds/assoc_container.hpp> // Common file 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
// #define ook order_of_key    //count of strictly smaller elements
// #define fbo find_by_order   //find element at an index 
// ******** Using PBDS ********
using namespace std;
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
#define vll vector<ll>
#define vec vector
#define setcount(x) __builtin_popcountll(x)
#define f first
#define s second
#define mp make_pair
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define REV(i,a,b) for(ll i=(a);i>=(b);i--)
#define pb push_back
#define in insert
#define init(x,a) memset(x,a,sizeof(x))
#define all(c) c.begin(),c.end()
#define pq priority_queue
#define ffl fflush(stdout)
#define mset multiset
#define out(x) cout<<#x<<" = "<<" "<<x<<"\n";
#define ub upper_bound
#define lb lower_bound 
#define ln "\n"
#define Y "YES"
#define N "NO"
ll const mod=1e9 + 7;
ll const inf=2e18;
// ******** Using PBDS ********
// typedef tree<long long, null_type, less<long long>, rb_tree_tag, 
//              tree_order_statistics_node_update> 
//                 os; 
// ******** Using PBDS ********
inline ll add(ll a,ll b) 
{ 
	return (a%mod + b%mod + mod)%mod; 
}
inline ll mul(ll a,ll b) 
{ 
	return (a%mod * b%mod + mod)%mod; 
}
inline ll sub(ll a,ll b) 
{ 
	return (a%mod - b%mod + mod)%mod; 
}
ll gcd(ll a,ll b)
{
	if (b == 0) 
		return a; 
	return gcd(b, a % b);  
}
ll modexp(ll x, ll n){
	if(n==0){
		return 1;
	}
	else if(n&1){
		return (modexp((x*x)%mod, n/2)%mod * x%mod)%mod;
	}
	else{
		return (modexp((x*x)%mod, n/2)%mod);
	}
}
ll modinv(ll n)
{
	return modexp(n,mod-2);
}
// ******** GLOBAL VARIABLES ********
	ll n;
// ******** GLOBAL VARIABLES ********
ll dp[10005][4];
ll a[10005];
ll fun(ll i,ll x)
{
	if(i==n)
	{
		return 0;
	}
	if(dp[i][x]!=-1)
	{
		return dp[i][x];
	}
	ll ans=1000000;
	if (a[i] < a[i - 1]) {
		REP(k,x)
		{
			ans=min(ans,fun(i+1,k));
		}
		for(int k=x;k<4;k++)
		{
			ans=min(ans,fun(i+1,k)+1);
		}
	} else if (a[i] > a[i - 1]) {
		REP(k,x+1)
		{
			ans=min(ans,fun(i+1,k)+1);
		}
		for(int k=x+1;k<4;k++)
		{
			ans=min(ans,fun(i+1,k));
		}
	} else {
		for (ll k = 0; k < 4; k++) {
			if (k == x) {
				ans=min(ans,fun(i+1,k));
			} else {
				ans=min(ans,fun(i+1,k)+1);
			}
		}
	}
	dp[i][x]=ans;
	return ans;
}
void solve(){
	cin>>n;
	init(dp,-1);
	REP(i,n)
	{
		cin>>a[i];
	}
	ll ans=n;
	REP(i,4)
	{
		ans=min(ans,fun(1,i));
	}
	cout<<ans<<ln;
}  
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll T=1;
	cin>>T; 	
	for(int t=1;t<=T;t++)
	{
		cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}