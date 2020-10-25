#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    ll s,a,b,c;
    ll ans;
    while(t--)
    {
        ans=0;
        cin>>s>>a>>b>>c;
        ll temp=s/(a*c);
        ans+=(temp*(a+b));
        s-=(temp*a*c);
        ans+=(s/c);
        cout<<ans<<endl;
        
    }
    return 0;
}