/*
    ThunderClap and Flash
    Raunaq Singh
*/
#include "bits/stdc++.h" 
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
inline ll add(ll a, ll b){ return ((a%mod) + (b%mod))%mod;}
inline ll mul(ll a, ll b){ return ((a%mod) * (b%mod))%mod;}
inline ll sub(ll a, ll b){ return ((a%mod) - (b%mod) + mod)%mod;}

void Flash(){
    ll n;
    cin>>n;
    vector <vector <ll>> a (n, vector <ll> (2, 0));
    for (ll i = 0; i < n; i++) {
        cin>>a[i][0]>>a[i][1];
    }
    ll mx[4], mn[4];
    for (ll i = 0; i < 4; i++) {
        mx[i] = -1 * inf;
        mn[i] = inf;
    }
    for (ll i = 0; i < n; i++) {
        mx[0] = max(mx[0], -1 * a[i][0] - a[i][1]);
        mx[1] = max(mx[1], -1 * a[i][0] + a[i][1]);
        mx[2] = max(mx[2], a[i][0] - a[i][1]);
        mx[3] = max(mx[3], a[i][0] + a[i][1]);

        mn[0] = min(mn[0], -1 * a[i][0] - a[i][1]);
        mn[1] = min(mn[1], -1 * a[i][0] + a[i][1]);
        mn[2] = min(mn[2], a[i][0] - a[i][1]);
        mn[3] = min(mn[3], a[i][0] + a[i][1]);
    }
    ll ans = -1 * inf;
    for (ll i = 0; i < 4; i++) {
        ans = max(ans, mx[i] - mn[i]);
    }
    cout<<ans<<"\n";
}

int main(int argc, char const *argv[]){ 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    ThunderClap;
    ll t = 1;
    for(ll i = 1; i <= t; i++){
        //cout<<"Case #"<<i<<": ";
        Flash();
    }
    return 0;
}
