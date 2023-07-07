// two pointer approach

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

int minSubArrayLen(int target, vector<int> &nums)
{
    int window = INT_MAX;
    int n = nums.size();
    int l = -1;
    int r = 0;
    int sum = nums[0];

    while (r < n && l < n)
    {
        if (sum < target)
        {
            r++;
            if (r >= n)
            {
                break;
            }
            sum += nums[r];
        }
        else
        {
            if (sum >= target)
            {
                window = min(window, r - l);
            }
            l++;
            if (l >= n)
            {
                break;
            }
            sum -= nums[l];
        }
    }
    if (window == INT_MAX)
    {
        return 0;
    }
    return window;
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
    }
    return 0;
}