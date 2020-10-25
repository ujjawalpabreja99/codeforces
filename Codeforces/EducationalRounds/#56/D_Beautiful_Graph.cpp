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
#define mod 998244353

ll BFS(vector<int> g[], int u,bool visited[],bool group[],int d[])
{
    visited[u]=1;
    queue<int> q;
    q.push(u);
    d[u]=0;
    group[u]=0;
    ll count0=0,count1=0;
    count0++;
    ll ans=0;

    while(q.empty()==0)
    {
        u=q.front();
        q.pop();
        for(int i=0;i<g[u].size();i++)
        {
            if(visited[g[u][i]]==1)
            {
                if(group[u]==group[g[u][i]])
                    return -1;
                else
                    continue;
            }
            int v=g[u][i];
            d[v]=d[u]+1;
            visited[v]=1;
            q.push(v);
            if(d[v]%2)
                {
                    group[v]=1;
                    count1++;
                }
            else
                {
                    count0++;
                    group[v]=0;
                }
        }

    }
    ll aalo=1,aalo1=1;
    for(int i=0;i<count0;i++)
        aalo=(aalo*2)%mod;
    for(int i=0;i<count1;i++)
        aalo1=(aalo1*2)%mod;

        ans=aalo;
    ans=(ans+aalo1)%mod;
    if(count1==0)
    {
        return 3;
    }
    return ans;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    int n,m;
    cin>>t;

    while(t--)
    {
        cin>>n>>m;
        vector<int> g[n];
        int u,v;
        for(int i=0;i<m;i++)
        {
            cin>>u>>v;
            g[u-1].push_back(v-1);
            g[v-1].push_back(u-1);
        }
        bool visited[n]={0};
        bool group[n]={0};
        int d[n]={0};
        ll ans=1;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
                ll temp=BFS(g,i,visited,group,d);
                if(temp==-1)
                    {
                        ans=0;
                        break;
                    }
                
                ans=(ans*temp)%mod;
            }
        }
        cout<<ans<<endl;
    }


    return 0;
}