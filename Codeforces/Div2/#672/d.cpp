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

    ll n,k;
    cin>>n>>k;
    vector<pair<ll,ll> >v,v1;
    ll fact[n+1];
    fact[0]=1;
    for(ll i=1;i<=n;i++)
        fact[i]=mul(fact[i-1],i);
    
    for(ll i=0;i<n;i++)
    {
        ll l,r;
        cin>>l>>r;
        v.push_back(make_pair(l,r));
        v1.push_back(make_pair(l,1));
        v1.push_back(make_pair(r,2));
    }
    sort(v1.begin(),v1.end());
    ll count=0;
    ll ans=0;
    for(ll i=0;i<v1.size();i++)
    {
        if(v1[i].second==2)
            count--;
        else
        {
            count++;
            if(count>=k)
            {
                ll num=fact[count-1];
                ll den=mul(fact[k-1],fact[count-k]);
                ll z=mul(num,modInv(den));
                ans=add(ans,z);
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}


