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
    ll a[n], b[n];
    map <ll, ll> freqA, freqB;
    for (ll i = 0; i < n; i++) {
        cin>>a[i];
        ++freqA[a[i]];
    }
    for (ll i = 0; i < n; i++) {
        cin>>b[i];
        ++freqB[b[i]];
    }
    bool chk = true;
    for (auto it: freqA) {
        if (it.s > (n - freqB[it.f])) {
            chk = false;
            break;
        }
    }
    if (!chk) {
        cout<<"No\n";
        return;
    }
    ll start = 0, end = n - 1;
    reverse(b, b + n);
    for (ll i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            if (i > start) {
                if (b[start] != a[i] && a[start] != b[i]) {
                    swap(b[start], b[i]);
                    ++start;
                } else {
                    swap(b[end], b[i]);
                    --end;
                }
            } else if (i < end) {
                if (b[end] != a[i] && a[end] != b[i]) {   
                    swap(b[end], b[i]);
                    --end;
                } else {
                    swap(b[start], b[i]);
                    ++start;
                }
            }
        }
    }
    /*
    for (ll i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            cout<<"No\n";
            return;
        }
    }
    */
    cout<<"Yes\n";
    for (ll i = 0; i < n; i++) {
        cout<<b[i]<<" ";
    }
    cout<<"\n";
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
