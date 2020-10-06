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
#define MAX 300010LL
#define mod 1000000007LL
#define inf 1000000000000000000LL
#define mI2 500000004LL
inline ll add(ll a, ll b){ return ((a%mod) + (b%mod))%mod;}
inline ll mul(ll a, ll b){ return ((a%mod) * (b%mod))%mod;}
inline ll sub(ll a, ll b){ return ((a%mod) - (b%mod) + mod)%mod;}

ll tree[8 * MAX + 1];

void merge(ll treeNode, ll leftNode, ll rightNode){
    tree[treeNode] = max(tree[leftNode], tree[rightNode]);
}

void build(ll start, ll end, ll treeNode){
    if(start == end){
        tree[treeNode] = 0;
        return; 
    }
    ll mid = (start + end);
    mid >>= 1;
    ll leftNode = 2 * treeNode;
    ll rightNode = 2 * treeNode + 1;
    build(start, mid, leftNode);
    build(mid + 1, end, rightNode);
    merge(treeNode, leftNode, rightNode);
}

void update(ll start, ll end, ll left, ll right, ll val, ll treeNode){
    ll mid = (start + end);
    mid >>= 1;
    ll leftNode = 2 * treeNode;
    ll rightNode = 2 * treeNode + 1;
    if(start >= left && end <= right){
            tree[treeNode] = val;
            return;
    }
    if(start > right || end < left){
            return;
    }
    update(start, mid, left, right, val, leftNode);
    update(mid+1, end, left, right, val, rightNode);
    merge(treeNode, leftNode, rightNode);
}

ll query(ll start, ll end, ll left, ll right, ll treeNode){
    ll mid = (start + end);
    mid >>= 1;
    ll leftNode = 2 * treeNode;
    ll rightNode = 2 * treeNode + 1;
    if(start >= left && end <= right){
            return tree[treeNode];
    }
    if(start > right || end < left){
            return 0;
    }
    ll leftQuery = query(start, mid, left, right, leftNode);
    ll rightQuery = query(mid + 1, end, left, right, rightNode);
    ll ret = max(leftQuery, rightQuery);
    return ret;
}

void Flash(){
    ll n, k;
    cin>>n>>k;
    ll a[n];
    for (ll i = 0; i < n; i++) {
        cin>>a[i];
    }
    ll leftMax, rightMax;
    ll maxAns = 1;
    ll currAns;
    build(0, 2 * MAX, 1);
    for (ll i = 0; i < n; i++) {
        leftMax = query(0, 2 * MAX, a[i] - k + MAX, a[i] + k + MAX, 1);
        currAns = leftMax + 1;
        //cout<<currAns<<"\n";
        update(0, 2 * MAX, a[i] + MAX, a[i] + MAX, currAns, 1);
        maxAns = max(currAns, maxAns);
    }
    cout<<maxAns<<"\n";
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
