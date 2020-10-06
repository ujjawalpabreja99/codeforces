/**
 * Written by : Ujjawal Pabreja [cuber_coder]
 * Email : ujjawalpabreja99@gmail.com
*/
#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
#define endl "\n"
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const ll MAX = 2e5 + 1;

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
    cin >> n;
    int a[n], mergeA[n], temp[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mergeA[i] = a[i];
    }
    ll x = 0, minInversions = mergeSort(mergeA, temp, 0, n - 1);
    for (int i = 30; i >= 0; i--) {
        int cur[n], mergeCur[n];
        for (int j = 0; j < n; j++) {
            cur[j] = mergeCur[j] = a[j] ^ (1LL << i);
        }
        ll curInversions = mergeSort(mergeCur, temp, 0, n - 1);
        if (curInversions < minInversions) {
            minInversions = curInversions;
            for (int j = 0; j < n; j++) {
                a[j] ^= (1LL << i);
            }
            x |= (1LL << i);
        }
    }
    cout << minInversions << " " << x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcases = 1;
    // cin >> testcases;

    while (testcases--) {
        Solve();
    }
    return 0;
}