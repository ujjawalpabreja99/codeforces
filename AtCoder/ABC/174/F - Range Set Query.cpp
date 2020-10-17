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
#define MAX 500001LL
#define mod 1000000007LL
#define inf 1000000000000000000LL
#define mI2 500000004LL
inline ll add(ll a, ll b){ return ((a%mod) + (b%mod))%mod;}
inline ll mul(ll a, ll b){ return ((a%mod) * (b%mod))%mod;}
inline ll sub(ll a, ll b){ return ((a%mod) - (b%mod) + mod)%mod;}

struct Query {
    ll l, r, ind;
};

bool compare (Query A, Query B) {
    return (A.r < B.r);
}

ll ft[MAX];
ll vis[MAX];

void update(ll i, ll val){
    while(i < MAX){
        ft[i] += val;
        i += (i & (-i));
    }
}

ll query(ll i){
    ll ret = 0;
    while(i > 0){
        ret += ft[i];
        i -= (i & (-i));
    }
    return ret;
}

void Flash(){
    ll n, q;
    cin>>n>>q;
    ll a[n + 1];
    for (ll i = 1; i <= n; i++) {
        cin>>a[i];
    }
    memset(vis, -1, sizeof(vis));
    memset(ft, 0, sizeof(ft));
    ll l, r;
    Query qq[q];
    for (ll i = 0; i < q; i++) {
        cin>>qq[i].l>>qq[i].r;
        qq[i].ind = i;
    }
    sort (qq, qq + q, compare);
    ll ans[q];
    memset(ans, -1, sizeof(ans));
    ll currPtr = 1;
    ll queryPtr = 0;
    while (currPtr <= n) {
        if (vis[a[currPtr]] != -1) {
            update(vis[a[currPtr]], -1);
        }

        vis[a[currPtr]] = currPtr;
        update(currPtr, 1);

        while (queryPtr < q && currPtr >= qq[queryPtr].r) {
            //debugg(queryPtr);
            ans[qq[queryPtr].ind] = (query(qq[queryPtr].r) - query(qq[queryPtr].l - 1));
            ++queryPtr;
        }
        ++currPtr;
    }

    for (ll i = 0; i < q; i++) {
        cout<<ans[i]<<"\n";
    }
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
