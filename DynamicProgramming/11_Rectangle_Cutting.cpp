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
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, MOD));
    for (int i = 1; i <= a; i++)
    {
        dp[i][1] = i - 1;
    }
    for (int i = 1; i <= b; i++)
    {
        dp[1][i] = i - 1;
    }
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (i == j)
            {
                dp[i][j] = 0;
                continue;
            }
            for (int k = 1; k <= j - 1; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i][k] + 1);
            }
            for (int k = 1; k <= i - 1; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j] + 1);
            }
        };
    }
    cout << dp[a][b];
    return 0;
}