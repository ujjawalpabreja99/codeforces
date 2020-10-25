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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  char s[n+1];
  cin >> s;

  ll count1 = 1, count2 = 1;
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1])
      count1++;
    else
      break;
  }
  for (int i = n - 2; i >= 0; i--) {
    if (s[i] == s[i + 1])
      count2++;
    else
      break;
  }
  if(count1==n)
  {
      cout<<(((n)*(n+1))/2)%mod;
        return 0;
  }

  ll ans = 0;
  if (s[0] != s[n - 1]) {
    ans = (ans + count1) % mod;
    ans = (ans + count2) % mod;
    ans = (ans + 1) % mod;
    cout << ans;
    return 0;
  }
//   cout<<count1<<" "<<count2<<endl;
  ll temp = 0;
  while (temp <= count1 && temp <= count2) {
    ans = (((ans + temp)%mod) + 1) % mod;
    temp++;
  }

  while (temp <= count1) {
    ans = (((ans + count2)%mod) + 1) % mod;
    temp++;
  }
  while (temp <= count2) {
    ans = (((ans + min(count1,count2))%mod) + 1) % mod;
    temp++;
  }

    while(temp<=count1+count2){
        ans=(ans+count1+count2-temp+1)%mod;
        temp++;
    }

  cout << ans;
  return 0;
}