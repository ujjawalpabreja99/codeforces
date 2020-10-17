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

bool chk (ll mid, ll a[], ll n, ll k) {
    ll ret = 0;
    for (ll i = 0; i < n; i++) {
        ret += (a[i] / mid);
        if ((a[i] % mid) == 0){
            --ret;
        }
    }
    return (ret <= k);
}

void Flash(){
    ll n, k;
    cin>>n>>k;
    ll a[n];
    ll mx = -1;
    for (ll i = 0; i < n; i++) {
        cin>>a[i];
        mx = max(mx, a[i]);
    }
    ll high = mx, low = 1, mid;
    ll ans = mx;
    while (high >= low) {
        mid = (high + low) >> 1;
        if (chk(mid, a, n, k)) {
            ans = mid;
            high = mid - 1; 
        } else {
            low = mid + 1;
        }
    }
    cout<<ans<<"\n";
}

int main(int argc, char const *argv[]){ 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    ThunderClap;
    ll t = 1;
    //cin>>t;
    for(ll i = 1; i <= t; i++){
        //cout<<"Case #"<<i<<": ";
        Flash();
    }
    return 0;
}
