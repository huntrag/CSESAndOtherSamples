#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
#define mp make_pair
#define MOD 1000000007
#define fi first
#define se second

int minRefuelStopsDP(int tar, int init, vector<vector<int>> &stat)
{
    reverse(stat.begin(), stat.end());
    stat.push_back(vector<int>({0, init}));
    reverse(stat.begin(), stat.end());
    stat.push_back(vector<int>({tar, 0}));
    int n = stat.size();
    vector<vector<long>> dp(n, vector<long>(n + 1, LONG_MIN));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (dp[i][j] == LONG_MIN)
            {
                continue;
            }
            long fuel = (long)dp[i][j] + stat[i][1];
            for (int k = i + 1; k < n; k++)
            {
                if (stat[i][0] + fuel >= stat[k][0])
                {
                    dp[k][j + 1] = max(dp[k][j + 1], (long)stat[i][0] + fuel - stat[k][0]);
                }
                else
                {
                    break;
                }
            }
        }
    }
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if (dp[n - 1][i] != LONG_MIN)
        {
            ans = i - 1;
            break;
        }
    }
    return ans;
}

int minRefuelStops(int tar, int init, vvi &stat)
{
    int n = stat.size();
    vll dp(n + 1, 0);
    dp[0] = (ll)init;

    for (int i = 0; i < n; i++)
    {
        for (int t = i; t >= 0; t--)
        {
            if (dp[t] > stat[i][0])
            {
                dp[t + 1] = max(dp[t + 1], (ll)dp[t] + stat[i][1]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (dp[i] > tar)
        {
            return i;
        }
    }
    return -1;
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
        int n, tar, init;
        cin >> n >> tar >> init;
        vector<vector<int>> a(n, vector<int>(2));

        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            a[i][0] = x;
            a[i][1] = y;
        }

        cout << minRefuelStops(tar, init, a);
    }
    return 0;
}