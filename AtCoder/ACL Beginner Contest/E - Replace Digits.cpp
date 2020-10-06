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
#define MAX 200001LL
#define mod 998244353LL
#define inf 1000000000000000000LL
#define mI2 500000004LL
inline ll add(ll a, ll b){ return ((a%mod) + (b%mod))%mod;}
inline ll mul(ll a, ll b){ return ((a%mod) * (b%mod))%mod;}
inline ll sub(ll a, ll b){ return ((a%mod) - (b%mod) + mod)%mod;}

ll a[MAX+1];
ll tree[4*MAX+1];
ll lazy[4*MAX+1];
ll value[10][MAX + 1];

ll modexp(ll x, ll n){
    if(n==0){
        return 1;
    }else if(n&1){
        return ((x%mod)*(modexp((x%mod*x%mod),n/2)%mod)%mod)%mod;
    }else{
        return modexp((x%mod*x%mod),n/2)%mod;
    }
}

void merge(ll treeNode, ll leftNode, ll rightNode, ll len){
    tree[treeNode] = add(mul(tree[leftNode], modexp(10, len)), tree[rightNode]);
}

void propagate(ll leftNode, ll rightNode, ll val){
    lazy[leftNode] = val;
    lazy[rightNode] = val;
}

void build(ll start, ll end, ll treeNode){
    lazy[treeNode] = 0;
    if(start == end){
        tree[treeNode] = 1;
        return; 
    }
    ll mid = (start + end);
    mid >>= 1;
    ll leftNode = 2 * treeNode;
    ll rightNode = 2 * treeNode + 1;
    build(start, mid, leftNode);
    build(mid + 1, end, rightNode);
    merge(treeNode, leftNode, rightNode, end - mid);
}

void update(ll start, ll end, ll left, ll right, ll val, ll treeNode){
    ll mid = (start + end);
    mid >>= 1;
    ll leftNode = 2 * treeNode;
    ll rightNode = 2 * treeNode + 1;
    ll len = end - start + 1;
    if(lazy[treeNode]){
        if(start != end){
            propagate(leftNode, rightNode, lazy[treeNode]);
        }
        tree[treeNode] = value[lazy[treeNode]][len];
        lazy[treeNode] = 0;
    }
    if(start >= left && end <= right){
        tree[treeNode] = value[val][len];
        if(start != end){
            propagate(leftNode, rightNode, val);
        }
        return;
    }
    if(start > right || end < left){
            return;
    }
    update(start, mid, left, right, val, leftNode);
    update(mid+1, end, left, right, val, rightNode);
    merge(treeNode, leftNode, rightNode, end - mid);
}

ll query(ll start, ll end, ll left, ll right, ll treeNode){
    ll mid = (start + end);
    mid >>= 1;
    ll leftNode = 2 * treeNode;
    ll rightNode = 2 * treeNode + 1;
    ll len = (end - start + 1); 
    if(lazy[treeNode]){
        if(start != end){
            propagate(leftNode, rightNode, lazy[treeNode]);
        }
        tree[treeNode] = value[lazy[treeNode]][len];
        lazy[treeNode] = 0;
    }
    if(start >= left && end <= right){
            return tree[treeNode];
    }
    if(start > right || end < left){
            return 0;
    }
    ll leftQuery = query(start, mid, left, right, leftNode);
    ll rightQuery = query(mid + 1, end, left, right, rightNode);
    ll ret = add(mul(leftQuery, modexp(10, end - mid)), rightQuery);
    return ret;
}

void Flash(){
    ll n, q;
    cin>>n>>q;
    build(1, n, 1);
    for (ll i = 0; i < 10; i++) {
        value[i][1] = i;
        for (ll j = 2; j <= n; j++) {
            value[i][j] = add(mul(value[i][j - 1], 10), i);
        }
    }
    ll l, r, d;
    while (q--) {
        cin>>l>>r>>d;
        update(1, n, l, r, d, 1);
        cout<<tree[1]<<"\n";
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
