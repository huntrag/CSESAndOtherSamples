#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= coins[i - 1] && dp[i][j - coins[i - 1]] >= 0)
            {
                if (dp[i][j] == -1 && dp[i][j - coins[i - 1]] >= 0)
                {
                    dp[i][j] = (int)(dp[i][j - coins[i - 1]] + 1) % MOD;
                }
                else
                {
                    dp[i][j] = (int)min(dp[i][j], (dp[i][j - coins[i - 1]] + 1)) % MOD;
                }
            }
            // cout << dp[i][j] << " ";
        }
        // cout << '\n';
    }
    cout << dp[n][k];
    return 0;
}