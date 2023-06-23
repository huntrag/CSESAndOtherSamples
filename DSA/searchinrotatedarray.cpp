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

int binary(vector<int> &a)
{
    int n = a.size();
    int key = a[n - 1];

    int low = 0;
    int high = n - 1;
    int mid;

    while (high - low >= 1)
    {
        if (high - low == 1)
        {
            if (a[high] < a[low])
            {
                return high;
            }
            else
            {
                return low;
            }
        }
        mid = (low + high) / 2;
        if (a[mid] > a[mid + 1])
        {
            return mid + 1;
        }
        if (a[mid] < key)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }

    return 0;
}

int binarysearch(vector<int> &a, int low, int high, int key)
{
    int mid;

    while (high - low >= 1)
    {
        if (high - low == 1)
        {
            if (a[high] == key)
            {
                return high;
            }
            else if (a[low] == key)
            {
                return low;
            }
            else
            {
                return -1;
            }
        }
        mid = (low + high) / 2;
        if (a[mid] == key)
        {
            return mid;
        }
        else if (a[mid] < key)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }

    if (a[low] == key)
    {
        return low;
    }
    else
    {
        return -1;
    }
}

int search(vector<int> &nums, int target)
{
    int ind = 0;
    int start = binary(nums);
    int first = binarysearch(nums, 0, start - 1, target);
    if (first == -1)
    {
        return binarysearch(nums, start, nums.size() - 1, target);
    }
    return first;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    //    cin>>test;
    while (test--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int t;
        cin >> t;
        cout << search(a, t);
    }
    return 0;
}