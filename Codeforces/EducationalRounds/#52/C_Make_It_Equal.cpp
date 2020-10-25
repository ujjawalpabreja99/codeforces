#include <bits/stdc++.h>
#include<queue>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    sort(arr,arr+n,greater<ll>());
    
    for(int i=0;i<n;i++)
    {
        arr[i]=arr[i]-arr[n-1];
    }
    
    queue<ll> q;
    ll lmao=0;
    for(int i=0;i<n;i++)
    {
        int j;
        for(j=i+1;j<n;j++)
            if(arr[j]!=arr[j-1])
                break;
        if(j!=n)
        {
            ll ab=arr[j-1]-arr[j];
            while(ab--)
            {
            q.push(j-i+lmao);}
        }
        lmao=j-i+lmao;
        i=j-1;
    }
    ll ans=0;
    ll sum=0;
    while(q.empty()==0)
    {
        ll f=q.front();
        sum+=q.front();
        if(sum>k)
        {
            sum=q.front();
            ans++;
        }
        q.pop();
    }
    if(sum>0)
        ans++;
    cout<<ans;
    return 0;
}