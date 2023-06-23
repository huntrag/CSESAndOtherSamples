#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second

ll mergesort(ll *arr, ll low, ll high);

ll merge(ll *arr, ll low, ll high);

ll inversionCount(ll arr[], ll N);

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n;
    cin >> n;
    long long int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << inversionCount(arr, n);

    return 0;
}

ll mergesort(ll *arr, ll low, ll high)
{
    ll count = 0;
    ll mid = (low + high) / 2;
    if (low < high)
    {
        count += (ll)mergesort(arr, low, mid);
        count += (ll)mergesort(arr, mid + 1, high);
        count += (ll)merge(arr, low, high);
        return count;
    }
    else
    {
        return 0;
    }
}

ll merge(ll *arr, ll low, ll high)
{
    ll mid = (low + high) / 2;
    ll i = low, j = mid + 1;
    ll count = 0;
    ll temp[high - low + 1];
    ll temp_cnt = 0;
    while (i <= mid && j <= high)
    {
        if (arr[i] > arr[j])
        {
            temp[temp_cnt] = arr[j];
            count += (ll)(mid - i + 1);
            j++;
            temp_cnt++;
        }
        else
        {
            temp[temp_cnt] = arr[i];
            i++;
            temp_cnt++;
        }
    }
    while (i <= mid)
    {
        temp[temp_cnt] = arr[i];
        i++;
        temp_cnt++;
    }
    while (j <= high)
    {
        temp[temp_cnt] = arr[j];
        j++;
        temp_cnt++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
    return count;
}

ll inversionCount(ll *arr, ll n)
{
    return mergesort(arr, 0, n - 1);
}