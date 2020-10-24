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

ll func(ll a[],ll n,ll i,ll c,ll dp[][3])
{
    if(i==n)
        return 0;

    if(dp[i][c]!=-1)
        return dp[i][c];
    ll ans=func(a,n,i+1,c,dp);   
    if(c==1)
    {
        ans=max(ans,a[i]+func(a,n,i+1,2,dp));
    }
    else 
        ans=max(ans,func(a,n,i+1,1,dp)-a[i]);
    dp[i][c]=ans;
    return ans;
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
        ll n,q;
        cin>>n>>q;
        ll a[n];
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
        }
        while(q--)
        {
            ll l,r;
            cin>>l>>r;
        }
        ll dp[n+1][3];
        memset(dp,-1,sizeof(dp));
        ll ans=func(a,n,0,1,dp);
        cout<<ans<<endl; 
    }
    
    return 0;
}





