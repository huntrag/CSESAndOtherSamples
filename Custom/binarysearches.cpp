#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
#define MOD 1000000007
#define fi first
#define se second

// it will give last occurance of key and if not present
// it will give first occurance of first greater
int ceil_binary_search(vector<int> &a, int key)
{
    int low = 0;
    int high = a.size();
    int mid;

    while ((high - low) > 1)
    {
        mid = low + (high - low) / 2;

        if (a[mid] <= key)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
        // cout << mid << "\n";
    }
    if (a[low] < key)
    {
        return low + 1;
    }

    return low;
}

int floor_binary_search(vector<int> &a, int key)
{
    int low = -1;
    int high = a.size() - 1;

    int mid;
    while ((high - low) > 1)
    {
        mid = (low + high + 1) / 2;
        if (a[mid] < key)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    if (a[high] > key)
    {
        return low;
    }
    return high;
}

int lowerbound(vector<int> &a, int key)
{
    int low = -1;
    int high = a.size();

    int mid;
    while ((high - low) > 1)
    {
        mid = (low + high + 1) / 2;
        if (a[mid] < key)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }

    return high;
}

int upperbound(vector<int> &a, int key)
{
    int low = 0;
    int high = a.size();
    int mid;

    while (high - low > 1)
    {
        mid = (high + low + 1) / 2;
        if (a[mid] <= key)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    return high;
}

int mod_binary(vector<int> &a, int key)
{
    int low = -1;
    int high = a.size();

    int mid;
    while ((high - low) > 1)
    {
        mid = (low + high + 1) / 2;
        if (a[mid] < key)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}

int lowerboundd(vector<int> &a, int key)
{
    return lower_bound(a.begin(), a.end(), key) - a.begin();
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << ceil_binary_search(arr, 6) << "\n";
        // cout << floor_binary_search(arr, 3);
        // cout << mod_binary(arr, 0);
        // cout << lowerboundd(arr, 2);
        // cout << upperbound(arr, 1);
    }
    return 0;
}