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
 
    ll arr[3];
    for(int i=0;i<3;i++)
        cin>>arr[i];
    ll d;
    cin>>d;
    sort(arr,arr+3);
    ll ans=0;
    ll temp=0;
    ans+=max(temp,(d-(arr[1]-arr[0])));
    ans+=max(temp,(d-(arr[2]-arr[1])));
    cout<<ans;
    return 0;
}