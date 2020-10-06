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

ll Parent[MAX+1];
ll Rank[MAX+1];

ll Find(ll v){
    while(v!=Parent[v]){
        v=Parent[v];
    }
    return v;
}

ll Union(ll u, ll v){
    u=Find(u);
    v=Find(v);
    ll ret=-1;
    if(u==v){
        return ret;
    }
    if(Rank[u]<Rank[v]){
        Parent[u]=v,ret=v;
    }else if(Rank[v]<Rank[u]){
        Parent[v]=u,ret=u;
    }else{
        Parent[v]=u,++Rank[u],ret=u;
    }
    return ret;
}

void Flash(){
    ll n, m;
    ll u, v;
    cin>>n>>m;
    for (ll i = 1; i <= n; i++) {
        Parent[i] = i;
        Rank[i] = 1;
    }
    for (ll i = 0; i < m; i++) {
        cin>>u>>v;
        Union(u, v);
    }
    set <ll> ss;
    for (ll i = 1; i <= n; i++) {
        ss.insert(Find(i));
    }
    cout<<ss.size() - 1<<"\n";
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
