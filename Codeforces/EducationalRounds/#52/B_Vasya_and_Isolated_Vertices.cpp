#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    ll temp=m*2;
    if(temp>=n)
        cout<<0<<" ";
    else
        cout<<n-temp<<" ";
    
    if(m==0)
    {
        cout<<n;
        return 0;
    }
    
    ll rangei=0,rangef=0;
    temp=0;
    for(int i=1;;i++)
    {
        rangei=rangef;
        rangef+=i;
        if(m>rangei && m<=rangef)
        {
            cout<<n-i-1;
            break;
        }
        
    }
    return 0;
}