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
    ll b[n/2];
    ll a[n];
    for(int i=0;i<n/2;i++)
    {
        cin>>b[i];
    }
    a[0]=0;
    a[n-1]=b[0];
    for(int i=1;i<n/2;i++)
    {
        if(b[i]<=b[i-1])
        {
            a[i]=a[i-1];
            a[n-i-1]=b[i]-a[i];
        }
        else
        {
            a[n-i-1]=a[n-i];
            a[i]=b[i]-a[n-i-1];
        }
    }

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    return 0;
}