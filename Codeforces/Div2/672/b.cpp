/*
    Arushi Garg [reborn_75]
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
long long const mod = 1000000007; 
#define inf 1000000000000000000
inline ll add(ll a, ll b){ return ((a%mod)+(b%mod)+mod)%mod;}
inline ll mul(ll a, ll b){ return (((a%mod)*(b%mod))%mod+mod)%mod;}
inline ll sub(ll a, ll b){ return ((a%mod)-(b%mod)+mod)%mod;}

ll gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
}

ll power(ll x,ll y,ll m) 
{ 
    if (y == 0) 
        return 1; 
    ll p = power(x, y/2, m) % m;
    p = (p * p) % m; 
    return (y%2 == 0)? p : (x * p) % m; 
}

ll modInv(ll x)
{
    return power(x,mod-2,mod)%mod;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        map<ll,ll>mp;
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
            ll x=log2(a[i])+1; 
            mp[x]++;
        }
        ll ans=0;
        for(auto x:mp)
            ans=ans+(x.second*(x.second-1))/2;
        cout<<ans<<endl;
    }
    
    return 0;
}


