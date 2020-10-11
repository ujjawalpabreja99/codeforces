/**
 * Written by : Ujjawal Pabreja [cuber_coder]
 * Email : ujjawalpabreja99@gmail.com
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long
#define ll long long
#define ld long double
#define endl "\n"
const int mod = 1e9 + 7;
const int MAX = 2e5 + 1;

ll merge(int arr[], int temp[], int left, int mid, int right) {
    ll inv_count = 0;
    int i = left, j = mid, k = left;
    while (i < mid and j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i);
        }
    }
    while (i < mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
    return inv_count;
}

ll mergeSort(int arr[], int temp[], int left, int right) {
    if (left >= right) {
        return 0;
    }
    int mid = left + (right - left) / 2;
    ll inv_count = mergeSort(arr, temp, left, mid) + mergeSort(arr, temp, mid + 1, right);
    inv_count += merge(arr, temp, left, mid + 1, right);
    return inv_count;
}

void Solve() {
    int n;
    string s;
    cin >> n >> s;
    string t = s;
    reverse(t.begin(), t.end());
    vector <int> v[26], index(26);
    for (int i = 0; i < n; i++) {
        v[s[i] - 'a'].push_back(i);
    }
    int a[n], k = 0;
    for (int i = 0; i < n; i++) {
        a[k++] = v[t[i] - 'a'][index[t[i] - 'a']];
        index[t[i] - 'a']++;
    }
    int b[n];
    memset(b, 0, sizeof(b));

    cout << mergeSort(a, b, 0, n - 1) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcases = 1;
    // cin >> testcases;

    while (testcases--) {
        Solve();
    }
}