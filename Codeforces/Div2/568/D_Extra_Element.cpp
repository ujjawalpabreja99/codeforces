#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pi pair<int,int>
#define pl pair<ll,ll>
#define ppi pair<int,pi >
#define ppl pair<ll,pl >
#define ld long double
#define pb push_back
#define mod 1000000007
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    pair<ll,int> arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].first;
        arr[i].second=i;
    }
    sort(arr,arr+n);
 
    if(n<=3)
    {
        cout<<1;
        return 0;
    }
    for(int i=0;i<3;i++)
    {
        pair<ll,int> arr2[n-1];
        int j=0;
        for(int k=0;k<n;k++)
        {
            if(k==i)
                continue;
            arr2[j].first=arr[k].first;
            arr2[j++].second=arr[k].second;
        }
        bool flag=0;
        ll diff=arr2[1].first-arr2[0].first;
        for(int k=2;k<n-1;k++)
        {
            if(arr2[k].first-arr2[k-1].first!=diff)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            cout<<arr[i].second+1;
            return 0;
        }
        
    }
    ll diff=arr[1].first-arr[0].first;
    if(arr[2].first-arr[1].first!=diff)
    {
        cout<<-1;
        return 0;
    }
    bool flag=0;
    int p=0;
    int ans=1;
    for(int i=3;i<n;i++)
    {
        if(arr[i].first-arr[i-1-p].first==diff)
        {   p=0;
            continue;
        }
        if(flag==1)
        {
            cout<<-1;
            return 0;
        }
        p=1;
        flag=1;
        ans=arr[i].second+1;
 
    }
    cout<<ans;
 
    
 
    return 0;
}