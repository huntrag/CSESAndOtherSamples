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

ll GetCeilIndex(vector<ll> &arr, vector<ll> &T, ll l, ll r,
                ll key)
{
    while (r - l > 1)
    {
        ll m = l + (r - l) / 2;
        if (arr[T[m]] >= key)
            r = m;
        else
            l = m;
    }

    return r;
}

int lengthOfLIS(vector<ll> &arr)
{
    ll n = arr.size();
    vector<ll> tailIndices(n, 0);  // Initialized with 0
    vector<ll> prevIndices(n, -1); // initialized with -1

    ll len = 1; // it will always poll to empty location
    for (ll i = 1; i < n; i++)
    {
        if (arr[i] < arr[tailIndices[0]])
        {
            tailIndices[0] = i;
        }
        else if (arr[i] > arr[tailIndices[len - 1]])
        {
            prevIndices[i] = tailIndices[len - 1];
            tailIndices[len++] = i;
        }
        else
        {
            ll pos = GetCeilIndex(arr, tailIndices, -1,
                                  len - 1, arr[i]);

            prevIndices[i] = tailIndices[pos - 1];
            tailIndices[pos] = i;
        }
    }

    // cout << "LIS of given input" << endl;
    // for (ll i = tailIndices[len - 1]; i >= 0; i = prevIndices[i])
    //     cout << arr[i] << " ";
    // cout << endl;

    return (int)len;
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
    // cin >> test;
    while (test--)
    {
        int x;
        vector<ll> a;
        while (cin >> x)
        {
            a.push_back(x);
        }
        int n = a.size();
        cout << lengthOfLIS(a);
    }
    return 0;
}