#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pi pair<int, int>
#define pl pair<ll, ll>
#define ppi pair<int, pi>
#define ppl pair<ll, pl>
#define ld long double
#define pb push_back
#define mod 998244353

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    int ang;

    while(t--)
    {
        cin>>ang;
        ll temp=__gcd(180,ang);
        ll ans=180/temp;
        if(ang<=temp*(ans-2))
        {
            cout<<180/temp<<endl;
            continue;
        }
        else
        {
            cout<<(2*180)/temp<<endl;
        }
    }

    return 0;
}

