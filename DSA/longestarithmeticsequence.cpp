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

int longestArithSeqLength(vector<int> &nums)
{
    if (nums.size() <= 2)
    {
        return nums.size();
    }
    int n = nums.size();
    int diff = *max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end());

    vector<vector<int>> dp(n, vector<int>(2 * diff + 2, 0));
    int d;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            d = nums[i] - nums[j];
            dp[i][d + diff] = dp[j][d + diff] + 1;
        }
    }
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, *max_element(dp[i].begin(), dp[i].end()));
    }

    return mx + 1;
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
    // cin>>test;
    while (test--)
    {
        list<int> a;
        a.push_back(1);
        a.push_back(0);
        a.push_back(2);
        a.sort();

        for (auto it = a.begin(); it != a.end(); it++)
        {
            if (*it == 1)
            {
                a.erase(it);
            }
        }
    }
    return 0;
}