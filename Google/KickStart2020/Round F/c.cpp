/*
	Nishant Singh
	nishant.ns19@gmail.com
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
ll s;
bool vis[7][13];
// ******** GLOBAL VARIABLES ********
bool pos(ll x,ll y){
	if(x<=s && x>=1 && y>=1 && y<(2*x))
		return !vis[x][y];
	return false;
}
ll fun(ll x1,ll y1,ll x2,ll y2,bool turn,bool doneA,bool doneB,ll curr){
	// cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<turn<<" "<<curr<<endl;
	if(turn){
		ll ans=INT_MIN;
		bool ok=false;
		if(pos(x1,y1+1)){
			ok=true;
			vis[x1][y1+1]=true;
			ans=max(ans,fun(x1,y1+1,x2,y2,false,false,false,curr+1));
			vis[x1][y1+1]=false;
		}
		if(pos(x1,y1-1)){
			ok=true;
			vis[x1][y1-1]=true;
			ans=max(ans,fun(x1,y1-1,x2,y2,false,false,false,curr+1));
			vis[x1][y1-1]=false;
		}
		if((y1%2==0) && pos(x1-1,y1-1)){
			ok=true;
			vis[x1-1][y1-1]=true;
			ans=max(ans,fun(x1-1,y1-1,x2,y2,false,false,false,curr+1));
			vis[x1-1][y1-1]=false;
		}
		if((y1%2==1) && pos(x1+1,y1+1)){
			ok=true;
			vis[x1+1][y1+1]=true;
			ans=max(ans,fun(x1+1,y1+1,x2,y2,false,false,false,curr+1));
			vis[x1+1][y1+1]=false;
		}
		if(!ok){
			if(doneB)
			{
				return curr;
			}
			return fun(x1,y1,x2,y2,false,true,false,curr);
		}
		return ans;
	}
	else{
		bool ok=false;
		ll ans=INT_MAX;
		if(pos(x2,y2+1)){
			ok=true;
			vis[x2][y2+1]=true;
			ans=min(ans,fun(x1,y1,x2,y2+1,true,false,false,curr-1));
			vis[x2][y2+1]=false;
		}
		if(pos(x2,y2-1)){
			ok=true;
			vis[x2][y2-1]=true;
			ans=min(ans,fun(x1,y1,x2,y2-1,true,false,false,curr-1));
			vis[x2][y2-1]=false;
		}
		if((y2%2==0) && pos(x2-1,y2-1)){
			ok=true;
			vis[x2-1][y2-1]=true;
			ans=min(ans,fun(x1,y1,x2-1,y2-1,true,false,false,curr-1));
			vis[x2-1][y2-1]=false;
		}
		if((y2%2==1) && pos(x2+1,y2+1)){
			ok=true;
			vis[x2+1][y2+1]=true;
			ans=min(ans,fun(x1,y1,x2+1,y2+1,true,false,false,curr-1));
			vis[x2+1][y2+1]=false;
		}
		if(!ok){
			if(doneA){
				return curr;
			}
			return fun(x1,y1,x2,y2,true,false,true,curr);
		}
		return ans;
	}
}
void solve(){
	ll r1,r2,c1,c2,c;
	cin>>s>>r1>>c1>>r2>>c2>>c;
	init(vis,false);
	REP(i,c){
		ll x,y;
		cin>>x>>y;
		vis[x][y]=true;
	}
	vis[r1][c1]=true;
	vis[r2][c2]=true;
	cout<<fun(r1,c1,r2,c2,true,false,false,0)<<ln;
	// cout<<ans<<endl;
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