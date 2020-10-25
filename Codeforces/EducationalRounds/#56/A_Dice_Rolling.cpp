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
 
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        if(n%2==0)
        {
            cout<<n/2<<endl;
            continue;
        }
        cout<<1+((n-3)/2)<<endl;
 
    }
 
    return 0;
}