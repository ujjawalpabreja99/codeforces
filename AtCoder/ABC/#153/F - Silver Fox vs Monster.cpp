/*
    ThunderClap and Flash.
    Raunaq Singh
*/
#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define ThunderClap ios::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL);
#define debugg(something)   cout<<#something<<" - "<<something<<"\n";
#define vi vector
#define umap unordered_map
#define uset unordered_set
#define mset multiset
#define LB lower_bound
#define UB upper_bound
#define mp make_pair
#define pb push_back
#define in insert
#define s second
#define f first
#define pQueue priority_queue
#define maxElement *max_element
#define minElement *min_element
#define MAX 100000LL
#define mod 1000000007LL
#define inf 1000000000000000000LL
#define mI2 500000004LL
inline ll add(ll a, ll b){ return ((a%mod)+(b%mod))%mod;}
inline ll mul(ll a, ll b){ return ((a%mod)*(b%mod))%mod;}
inline ll sub(ll a, ll b){ return ((a%mod)-(b%mod)+mod)%mod;}

void Flash(){
    ll n,d,a;
    cin>>n>>d>>a;
    pll xh[n];
    for(ll i=0;i<n;i++){
        cin>>xh[i].f>>xh[i].s;
    }
    sort(xh,xh+n);
    ll x[n],h[n];
    ll dp[n+1]={};
    for(ll i=0;i<n;i++){
        x[i]=xh[i].f,h[i]=xh[i].s;
    }
    ll j;
    ll ans=0;
    ll bombsUsed;
    for(ll i=0;i<n;i++){
        dp[i+1]+=dp[i];
        h[i]+=(dp[i+1]);
        h[i]=max(h[i],0LL);
        j=(UB(x,x+n,x[i]+2*d)-x);
        bombsUsed=((h[i]/a) + ((h[i]%a)!=0));
        ans+=bombsUsed;
        dp[i+1]-=(bombsUsed*a);
        dp[j+1]+=(bombsUsed*a);
    }
    cout<<ans<<"\n";
}

int main(int argc, char const *argv[]){
    ThunderClap;
    ll t=1;
    //cin>>t;
    for(ll i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        Flash();
    }
    return 0;
}
