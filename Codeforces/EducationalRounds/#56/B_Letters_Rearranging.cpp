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
    string s;
    while(t--)
    {
        cin>>s;
        int arr[26]={0};
        for(int i=0;i<s.size();i++)
        {
            arr[s[i]-'a']++;
        }
        int count=0;
        for(int i=0;i<26;i++)
        {
            if(arr[i]!=0)
                count++;
        }
        if(count==1)
        {
            cout<<-1<<endl;
            continue;
        }
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<arr[i];j++)
            {
                cout<<(char)(i+'a');
            }
        }
        cout<<endl;

    }

    return 0;
}