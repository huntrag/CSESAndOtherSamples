// Binary search on answer
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
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
class Solution
{
public:
    vi prefix;

    ll getRange(int i, int j)
    {
        // including both i and j
        return prefix[j + 1] - prefix[i];
    }
    // DP method
    int splitArray(vector<int> &a, int k)
    {
        int n = a.size();
        prefix.resize(n + 1);
        prefix[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            prefix[i] = (ll)prefix[i - 1] + a[i - 1];
        }

        vvi dp(k + 1, vi(n, LLONG_MAX));
        for (int i = 0; i < n; i++)
        {
            dp[1][i] = getRange(0, i);
        }
        for (int i = 2; i <= k; i++)
        {
            for (int j = i - 1; j < n; j++)
            {
                for (int l = i - 1; l <= j; l++)
                {
                    dp[i][j] = min(dp[i][j], max(dp[i - 1][l - 1], getRange(l, j)));
                }
            }
        }
        return dp[k][n - 1];
    }

    // greedy method
    int splitArray1(vector<int> &nums, int m)
    {
        int l = 0, r = 0, n = nums.size();
        for (int i = 0; i < n; ++i)
            l = max(l, nums[i]), r += nums[i];

        int mid = 0, ans = 0;
        while (l <= r)
        {
            mid = (l + r) / 2;
            int count = 0, tempsum = 0;
            for (int i = 0; i < n; ++i)
            {
                if (tempsum + nums[i] <= mid)
                    tempsum += nums[i];
                else
                    count++, tempsum = nums[i];
            }
            count++;

            if (count <= m)
                r = mid - 1, ans = mid;
            else
                l = mid + 1;
        }
        return ans;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin>>test;
    while (test--)
    {
    }
    return 0;
}