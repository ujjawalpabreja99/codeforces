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
 
    ll n,m;
    cin>>n>>m;
    ll arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    ll sum=0;
    int ans=0;
    ll rem=0;
    multiset<ll,greater<int> > ms;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum<=m)
        {
            cout<<ans<<" ";
            ms.insert(arr[i]);
            continue;
        }
        auto it=ms.begin();
        ll temp=sum;
        int count=0;
        int finans=ans;
        while(temp>m)
        {   
            temp-=*it;
            rem+=*it;
            ans++;
            it++;
            count++;
        }
        cout<<ans<<" ";
        it=ms.begin();
        if(count==1 && *it>arr[i])
        {
            sum-=*it;
            ms.erase(ms.begin());
            ms.insert(arr[i]);
        }
        else
        {
            ans=finans+1;
            sum-=arr[i];
        }
        
    }
 
    return 0;
}