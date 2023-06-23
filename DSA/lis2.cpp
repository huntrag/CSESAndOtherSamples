#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
#define MOD 1000000007
#define fi first
#define se second

int lengthOfLIS(vector<int> &a, int k)
{
    vector<int> dp;
    vector<int>::iterator it;
    int prev, next;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        it = lower_bound(dp.begin(), dp.end(), a[i]);

        if (it == dp.end())
        {
            if (dp.size() == 0)
            {
                dp.push_back(a[i]);
            }
            else
            {
                prev = dp[dp.size() - 1];
                if ((a[i] - prev) <= k)
                {
                    dp.push_back(a[i]);
                }
            }
        }
        else if (it == dp.begin())
        {
            if (dp.size() > 1)
            {
                next = dp[1];
                if (next - a[i] <= k)
                {
                    dp[0] = a[i];
                }
            }
            else
            {
                dp[0] = a[i];
            }
        }
        else
        {
            *it = a[i];
        }
    }

    return dp.size();
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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << lengthOfLIS(a, k);
    }
    return 0;
}