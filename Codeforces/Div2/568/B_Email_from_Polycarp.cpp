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
    while(t--)
    {
        string s1,s2;
        cin>>s1>>s2;
        int i=0,j=0;
        int n=s1.size();
        int m=s2.size();
        bool flag=0;
        while(i<n)
        {
            if(j>=m)
            {
                flag=1;
                break;
            }
            if(i<n-1 && s1[i+1]==s1[i])
            {
                if(s2[j]==s1[i])
                {
                    j++;
                    i++;
                }
                else
                {
                    flag=1;
                    break;
                }
                continue;
            }
            if(s2[j]!=s1[i])
            {
                flag=1;
                break;
            }
            while(j<m && s2[j]==s1[i])
                j++;
            i++;
 
        }
        if(flag==1 || j<m)
        {
            cout<<"NO"<<endl;
        }
        else
            cout<<"YES"<<endl;
    }
 
    return 0;
}