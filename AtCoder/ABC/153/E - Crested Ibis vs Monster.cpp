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

ll findMin(ll i, ll h, ll a[], ll b[], ll dp[][10001], ll n){
    if(h<=0){
        return 0;
    }
    if(i==n){
        return mod;
    }
    if(dp[i][h]!=-1){
        return dp[i][h];
    }
    ll ret=min(findMin(i,h-a[i],a,b,dp,n)+b[i],findMin(i+1,h,a,b,dp,n));
    return dp[i][h]=ret;
}
                                        
void Flash(){
    ll h,n;
    cin>>h>>n;
    ll a[n],b[n];
    for(ll i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    ll dp[n][10001];
    memset(dp,-1,sizeof(dp));
    cout<<findMin(0,h,a,b,dp,n)<<"\n";
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
