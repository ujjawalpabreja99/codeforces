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
ll n,a,b;
// ******** GLOBAL VARIABLES ********
void fun(ll i, ll par, vector <ll> &p,ll m1[],ll m2[],vll g[]){
	m1[i]++;
	m2[i]++;
	p.pb(i);
	for(auto it : g[i])
	{
		if(it!= par){
			fun(it, i, p,m1,m2,g);
		}
	}
	ll temp=p.size();
	if(temp>=(a+1))
	{
		m1[p[temp-a-1]]+=m1[i];
	}
	if(temp>=(b+1))
	{
		m2[p[temp-b-1]]+=m2[i];
	}
	p.pop_back();
}
void solve(){
	cin>>n>>a>>b;
	ll temp[n];
	vll g[n];
	REP(i,n-1)
	{
		cin>>temp[i];
		temp[i]--;
		g[i+1].pb(temp[i]);
		g[temp[i]].pb(i+1);
	}
	ll moda[n+5],modb[n+5];
	init(moda,0);
	init(modb,0);
	vll p;
	fun(0,-1,p,moda,modb,g);
	ld den=(n*n);
	ld num=0;
	for(int i=0;i<n;i++)
	{
		num=num + (n*moda[i] + n*modb[i] - moda[i]*modb[i]);
	}
	cout<<fixed<<setprecision(12)<<(num/(ld)(den))<<ln;
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